#ifndef XSERRORMODE_H
#define XSERRORMODE_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Error modes for use in XsDevice::setErrorMode
	\sa XsDevice::setErrorMode \sa XsDevice::errorMode
*/
enum XsErrorMode {
	 XEM_Ignore = 0x0000					//!< Ignore all errors without warning
	,XEM_IncreasePacketCounter = 0x0001		//!< Increase packet counter when an error occurs, resulting in gaps in the packet counter
	,XEM_IncreasePacketCounterAndSendError = 0x0002	//!< Increase packet counter when an error occurs, resulting in gaps in the packet counter and send an explicit error message
	,XEM_SendErrorAndGoToConfig = 0x0003	//!< Abort measuring and send an error message
	,XEM_Invalid							//!< No error mode available (non-Xbus Master devices)
};
/*! @} */
typedef enum XsErrorMode XsErrorMode;

#endif // file guard
