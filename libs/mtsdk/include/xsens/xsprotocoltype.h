#ifndef XSPROTOCOLTYPE_H
#define XSPROTOCOLTYPE_H

/*!	\addtogroup enums Global enumerations
	@{
*/
//! Protocol types (XsDevice::enableProtocol())
enum XsProtocolType {
	 XPT_Xbus = 0		//!< The Xsens Xbus protocol, enabled by default, always 0
	,XPT_Nmea			//!< The NMEA protocol, only the messages that can be sent from Xsens devices are recognized
	,XPT_ImarFsas		//!< An iMAR FSAS communication protocol
	,XPT_ImarIfog		//!< An iMAR iFog communication protocol
};
/*! @} */
typedef enum XsProtocolType XsProtocolType;

#endif // file guard
