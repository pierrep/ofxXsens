#ifndef XSDEVICESTATE_H
#define XSDEVICESTATE_H

#include "xdaconfig.h"

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief XsDevice state identifiers */
enum XsDeviceState {
	XDS_Initial,					/*!< Initial unknown state */
	XDS_Config,						/*!< Configuration mode. */
	XDS_Measurement,				/*!< Measurement mode, devices are transmitting data. */
	XDS_WaitingForRecordingStart,	/*!< The device is in measurement mode and waiting for an external trigger to go to recording state. \note Awinda Station only */
	XDS_Recording,					/*!< Same as measurement mode, but on Awinda systems retransmissions now also occur. \note Only on an Awinda Station is this an actual state in the device. For other devices, the state exists only in XDA. */
	XDS_FlushingData,				/*!< The device has been notified that it should stop recording. It is still measuring data and may flush retransmitted data to XDA. When XDA decides that it will not receive any more data that should be recorded, the state will be switched to XDS_FinalizingRecording automatically */
	XDS_FinalizingRecording,		/*!< The device has been notified that it should stop recording. It is still measuring data and may flush retransmitted data to XDA. When XDA decides that it will not receive any more data that should be recorded, the state will be switched to XDS_Measurement automatically */
	XDS_Destructing					/*!< The device is being destructed. After this callback, the device and any references to it are invalid. */
};
/*! @} */
typedef enum XsDeviceState XsDeviceState;

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Convert the device state to a human readable string */
XDA_DLL_API const char *XsDeviceState_toString(XsDeviceState s);

#ifdef __cplusplus
} // extern "C"

/*! \brief \copybrief XsDeviceState_toString \sa XsDeviceState_toString */
inline const char *toString(XsDeviceState s)
{
	return XsDeviceState_toString(s);
}

#endif

#endif	// file guard
