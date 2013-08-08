#include "ofxXsens.h"
#include <xsensdeviceapi.h> // The Xsens device API header

#include "ofMain.h"
#include "ofxXsensCallbackHandler.h"
#include "serialkey.h"

void ofxXsens::setup()
{

    bSensorConnected = false;

    if (!setSerialKey())
	{
		ofLogError("ofxXsens") << "Invalid serial key." << std::endl;
		return;
	}

    // Create XsControl object
	ofLogNotice("ofxXsens") << "Creating XsControl object..." << std::endl;
	control = XsControl::construct();
	assert(control != 0);

}


void ofxXsens::connect()
{
    try {
        // Scan for connected devices
        ofLogNotice("ofxXsens") << "Scanning for devices...";
        XsPortInfoArray portInfoArray = XsScanner::scanPorts();

        // Find an MTi / MTx / MTmk4 device
        mtPort = portInfoArray.begin();
        while (mtPort != portInfoArray.end() && !mtPort->deviceId().isMtix() && !mtPort->deviceId().isMtMk4()) {++mtPort;}
        if (mtPort == portInfoArray.end())
        {
            throw std::runtime_error("No MTi / MTx / MTmk4 device found. Aborting.");
        }
        ofLogNotice("ofXsens") << "Found a device with id: " << mtPort->deviceId().toString().toStdString() << " @ port: " << mtPort->portName().toStdString() << ", baudrate: " << mtPort->baudrate();

        // Open the port with the detected device
        ofLogNotice("ofxXsens") << "Opening port..." << std::endl;
        if (!control->openPort(mtPort->portName().toStdString(), mtPort->baudrate()))
        {
            throw std::runtime_error("Could not open port. Aborting.");
        }
		try
		{
			// Get the device object
			XsDevice* device = control->device(mtPort->deviceId());
			assert(device != 0);

			// Print information about detected MTi / MTx / MTmk4 device
			ofLogNotice("ofxXsens") << "Device: " << device->productCode().toStdString() << " opened." << std::endl;

			//Attach callback handler to device
			device->addCallbackHandler(&callback);

			// Put the device in configuration mode
			ofLogNotice("ofxXsens") << "Putting device into configuration mode..." << std::endl;
			if (!device->gotoConfig()) // Put the device into configuration mode before configuring the device
			{
				throw std::runtime_error("Could not put device into configuration mode. Aborting.");
			}

			// Configure the device. Note the differences between MTix and MTmk4
			ofLogNotice("ofxXsens") << "Configuring the device..." << std::endl;
			if (device->deviceId().isMtix())
			{
				ofLogNotice("ofxXsens") << "isMtix..." << std::endl;
				XsOutputMode outputMode = XOM_Orientation; // output orientation data
				XsOutputSettings outputSettings = XOS_OrientationMode_Quaternion; // output orientation data as quaternion
				XsDeviceMode deviceMode(100); // make a device mode with update rate: 100 Hz
				deviceMode.setModeFlag(outputMode);
				deviceMode.setSettingsFlag(outputSettings);

				// set the device configuration
				if (!device->setDeviceMode(deviceMode))
				{
					throw std::runtime_error("Could not configure MTmki device. Aborting.");
				}
				bSensorConnected = true;
			}
			else if (device->deviceId().isMtMk4())
			{
				ofLogNotice("ofxXsens") << "isMtMk4..." << std::endl;
				XsOutputConfiguration quat(XDI_Quaternion, 0);
				//XsOutputConfiguration gpssol(XDI_GpsSol, 0);
				XsOutputConfiguration latlong(XDI_LatLon, 0);
				XsOutputConfigurationArray configArray;
				configArray.push_back(quat);
				//configArray.push_back(gpssol);
				configArray.push_back(latlong);
				if (!device->setOutputConfiguration(configArray))
				{

					throw std::runtime_error("Could not configure MTmk4 device. Aborting.");
				}
				bSensorConnected = true;
			}
			else
			{
				throw std::runtime_error("Unknown device while configuring. Aborting.");
			}

			// Put the device in measurement mode
			std::cout << "Putting device into measurement mode..." << std::endl;
			if (!device->gotoMeasurement())
			{
				throw std::runtime_error("Could not put device into measurement mode. Aborting.");
			}
		}
		catch (std::runtime_error const & error)
		{
			std::cout << error.what() << std::endl;
		}
		catch (...)
		{
			ofLogError("ofxXsens") << "An unknown fatal error has occured. Aborting." << std::endl;
		}
    }
    catch (runtime_error const & error)
    {
        ofLogError("ofxXsens") << error.what();
    }
    catch (...)
    {
        ofLogError("ofxXsens") << "An unknown fatal error has occured.";
    }
}

void ofxXsens::update() {

    if (callback.packetAvailable())
    {
            // Retrieve a packet
            XsDataPacket packet = callback.getNextPacket();

            //Get the quaternion data
            XsQuaternion quaternion = packet.orientationQuaternion();
            ofLogVerbose("ofxXsens") << "\r"
                      << "q0:" << std::setw(5) << std::fixed << std::setprecision(2) << quaternion.m_w
                      << ",q1:" << std::setw(5) << std::fixed << std::setprecision(2) << quaternion.m_x
                      << ",q2:" << std::setw(5) << std::fixed << std::setprecision(2) << quaternion.m_y
                      << ",q3:" << std::setw(5) << std::fixed << std::setprecision(2) << quaternion.m_z
            ;

            // Convert packet to euler
            euler = packet.orientationEuler();
            ofLogVerbose("ofxXsens") << ",Roll:" << std::setw(7) << std::fixed << std::setprecision(2) << euler.m_roll
                      << ",Pitch:" << std::setw(7) << std::fixed << std::setprecision(2) << euler.m_pitch
                      << ",Yaw:" << std::setw(7) << std::fixed << std::setprecision(2) << euler.m_yaw
            ;

            // GPS
            if(packet.containsLatitudeLongitude()) {
                lat_long = packet.latitudeLongitude();
                ofLogVerbose("ofxXsens") << "\n" << "Latitude:" <<  std::setprecision(9) << lat_long[0] << " Longitude:" << lat_long[1];
            }
            else
            if(packet.containsPositionLLA()) {
                ofLogVerbose("ofxXsens") << "\n" << "Packet contains position LLA data" ;
            }
            else
            if(packet.containsRawGpsSol()){
                ofLogVerbose("ofxXsens") << "\n" << "Packet contains RAW GPS data" ;
            }

    }

}

void ofxXsens::close()
{
    // Close port
    ofLogNotice("ofxXsens") << "Closing port..." << std::endl;
    control->closePort(mtPort->portName().toStdString());

    // Free XsControl object
    ofLogNotice("ofxXsens") << "Freeing XsControl object..." << std::endl;
	control->destruct();
}

double ofxXsens::getLatitude() {
    if(lat_long.size() >= 2)
    {
        return lat_long[0];
    }
    return 0.0;
}

double ofxXsens::getLongitude() {

    if(lat_long.size() >= 2)
    {
        return lat_long[1];
    }
    return 0.0;
}
