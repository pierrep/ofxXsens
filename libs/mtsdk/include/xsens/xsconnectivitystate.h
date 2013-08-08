#ifndef XSCONNECTIVITYSTATE_H
#define XSCONNECTIVITYSTATE_H

#include "xdaconfig.h"

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief XsDevice connectivity state identifiers */
enum XsConnectivityState {
	XCS_Disconnected,		/*!< Device has disconnected, only limited informational functionality is available. */
	XCS_Rejected,			/*!< Device has been rejected and is disconnected, only limited informational functionality is available. */
	XCS_PluggedIn,			/*!< Device is connected through a cable. */
	XCS_Wireless,			/*!< Device is connected wirelessly. */
	XCS_File,				/*!< Device is reading from a file. */
	XCS_Unknown,			/*!< Device is in an unknown state. */
};

/*! @} */
typedef enum XsConnectivityState XsConnectivityState;

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Convert the device state to a human readable string */
XDA_DLL_API const char *XsConnectivityState_toString(XsConnectivityState s);

#ifdef __cplusplus
} // extern "C"

/*! \brief \copybrief XsConnectivityState_toString \sa XsConnectivityState_toString */
inline const char *toString(XsConnectivityState s)
{
	return XsConnectivityState_toString(s);
}
#endif

#endif	// file guard
