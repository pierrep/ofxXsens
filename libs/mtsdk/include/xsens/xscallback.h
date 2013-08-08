#ifndef XSCALLBACK_H
#define XSCALLBACK_H

#include "xscallbackplainc.h"

#ifdef __cplusplus

/*! \brief Structure that contains callback functions for the Xsens Device API
	\details When programming in C++, simply overload the callback that you want to use and supply
	your XsCallbackPlainC-overloaded class to one of the setCallback functions

	When programming in C, create an XsCallbackPlainC structure and initialize each function pointer to
	the right function to call. The supplied first parameter is the address of the XsCallbackPlainC
	object that you supplied to the setCallback function. If you do not wish to receive a specific
	callback in C, set the function pointer to 0.

	In both cases, the calling application remains in control of the XsCallbackPlainC object and thus
	remains responsible for cleaning it up when the it is no longer necessary.

	\note Any callback function in %XsCallback that is not overloaded will only be called once to
	minimize callback overhead.
*/
class XsCallback : public XsCallbackPlainC
{
public:
	/*! \brief Constructor */
	XsCallback()
	{
		m_onDeviceStateChanged = sonDeviceStateChanged;
		m_onDataAvailable = sonDataAvailable;
		m_onMissedPackets = sonMissedPackets;
		m_onWakeupReceived = sonWakeupReceived;
		m_onProgressUpdated = sonProgressUpdated;
		m_onWriteMessageToLogFile = sonWriteMessageToLogFile;
		m_onWriteDataToLogFile = sonWriteDataToLogFile;
		m_onConnectivityChanged = sonConnectivityChanged;
		m_onInfoResponse = sonInfoResponse;
		m_onError = sonError;
		m_onNonDataMessage = sonNonDataMessage;
		m_onMessageReceivedFromDevice = sonMessageReceivedFromDevice;
		m_onMessageSentToDevice = sonMessageSentToDevice;
	}

	/*! \brief Destructor
		\note Make sure that the object is removed from callback generating objects before destroying it!
	*/
	virtual ~XsCallback() {}
		
private:
/*! \protectedsection
	\addtogroup Callbacks
	@{
*/
	//! \copybrief m_onDeviceStateChanged
	virtual void onDeviceStateChanged(XsDevice* dev, XsDeviceState newState, XsDeviceState oldState)
	{ (void) dev; (void) newState; (void) oldState; m_onDeviceStateChanged = 0; }
	//! \copybrief m_onDataAvailable
	virtual void onDataAvailable(XsDevice* dev, const XsDataPacket* packet)
	{ (void) dev; (void) packet; m_onDataAvailable = 0; }
	//! \copybrief m_onMissedPackets
	virtual void onMissedPackets(XsDevice* dev, int missedSamples)
	{ (void) dev; (void)missedSamples; m_onMissedPackets = 0; }
	//! \copybrief m_onWakeupReceived
	virtual void onWakeupReceived(XsDevice* dev)
	{ (void) dev; m_onWakeupReceived = 0; }
	//! \copybrief m_onProgressUpdated
	virtual void onProgressUpdated(XsDevice* dev, int current, int total, const XsString* identifier)
	{ (void) dev; (void) current; (void) total; (void)identifier; m_onProgressUpdated = 0; }
	//! \copydoc m_onWriteMessageToLogFile
	virtual int  onWriteMessageToLogFile(XsDevice* dev, const XsMessage* message)
	{ (void) dev; (void) message; m_onWriteMessageToLogFile = 0; return 1; }
	//! \copydoc m_onWriteDataToLogFile
	virtual int  onWriteDataToLogFile(XsDevice* dev, const XsDataPacket* data)
	{ (void) dev; (void) data; m_onWriteDataToLogFile = 0; return 1; }
	//! \copydoc m_onConnectivityChanged
	virtual void onConnectivityChanged(XsDevice* dev, XsConnectivityState newState)
	{ (void) dev; (void) newState; m_onConnectivityChanged = 0; }
	//! \copydoc m_onInfoResponse
	virtual void onInfoResponse(XsDevice* dev, XsInfoRequest request)
	{ (void) dev; (void) request; m_onInfoResponse = 0; }
	//! \copydoc m_onError
	virtual void onError(XsDevice* dev, XsResultValue error)
	{ (void) dev; (void) error; m_onError = 0; }	
	//! \copydoc m_onNonDataMessage
	virtual void onNonDataMessage(XsDevice* dev, XsMessage const * message)
	{ (void) dev; (void) message; m_onNonDataMessage = 0; }
	//! \copydoc m_onMessageReceivedFromDevice
	virtual void onMessageReceivedFromDevice(XsDevice* dev, XsMessage const * message)
	{ (void) dev; (void) message; m_onMessageReceivedFromDevice = 0; }
	//! \copydoc m_onMessageSentToDevice
	virtual void onMessageSentToDevice(XsDevice* dev, XsMessage const * message)
	{ (void) dev; (void) message; m_onMessageSentToDevice = 0; }
//! @}

/*! \privatesection */
	static void sonDeviceStateChanged(XsCallbackPlainC* cb, XsDevice* dev, XsDeviceState newState, XsDeviceState oldState) { ((XsCallback*)cb)->onDeviceStateChanged(dev, newState, oldState); }
	static void sonDataAvailable(XsCallbackPlainC* cb, XsDevice* dev, const XsDataPacket* packet) { ((XsCallback*)cb)->onDataAvailable(dev, packet); }
	static void sonMissedPackets(XsCallbackPlainC* cb, XsDevice* dev, int missedSamples) { ((XsCallback*)cb)->onMissedPackets(dev, missedSamples); }
	static void sonWakeupReceived(XsCallbackPlainC* cb, XsDevice* dev) { ((XsCallback*)cb)->onWakeupReceived(dev); }
	static void sonProgressUpdated(XsCallbackPlainC* cb, XsDevice* dev, int current, int total, const XsString* identifier) { ((XsCallback*)cb)->onProgressUpdated(dev, current, total, identifier); }
	static int  sonWriteMessageToLogFile(XsCallbackPlainC* cb, XsDevice* dev, const XsMessage* message) { return ((XsCallback*)cb)->onWriteMessageToLogFile(dev, message); }
	static int  sonWriteDataToLogFile(XsCallbackPlainC* cb, XsDevice* dev, const XsDataPacket* data) { return ((XsCallback*)cb)->onWriteDataToLogFile(dev, data); }
	static void sonConnectivityChanged(XsCallbackPlainC* cb, XsDevice* dev, XsConnectivityState newState) { ((XsCallback*)cb)->onConnectivityChanged(dev, newState); }
	static void sonInfoResponse(XsCallbackPlainC* cb, XsDevice* dev, XsInfoRequest request) { ((XsCallback*)cb)->onInfoResponse(dev, request); }
	static void sonError(XsCallbackPlainC* cb, XsDevice* dev, XsResultValue error) { ((XsCallback*)cb)->onError(dev, error); }	
	static void sonNonDataMessage(XsCallbackPlainC* cb, XsDevice* dev, XsMessage const * message) { ((XsCallback*)cb)->onNonDataMessage(dev, message); }	
	static void sonMessageReceivedFromDevice(XsCallbackPlainC* cb, XsDevice* dev, XsMessage const * message) { ((XsCallback*)cb)->onMessageReceivedFromDevice(dev, message); }
	static void sonMessageSentToDevice(XsCallbackPlainC* cb, XsDevice* dev, XsMessage const * message) { ((XsCallback*)cb)->onMessageSentToDevice(dev, message); }
};

#endif

#endif // file guard
