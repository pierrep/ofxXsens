#ifndef OFX_XSENS_H
#define OFX_XSENS_H

#include <xsensdeviceapi.h> // The Xsens device API header
#include "ofxXsensCallbackHandler.h"

class ofxXsens
{
    public:
        void setup();
        void connect();
        void update();
        void close();
        bool isConnected() {return bSensorConnected;};
        double getPitch() {return euler.m_pitch;};
        double getRoll() {return euler.m_roll;};
        double getYaw() {return euler.m_yaw;};
        double getLatitude();
        double getLongitude();

    private:
        bool bSensorConnected;
        XsControl* control;
        CallbackHandler callback;

        XsEuler euler;
        XsVector lat_long;
        XsPortInfoArray::const_iterator mtPort;
};

#endif // OFX_XSENS_H
