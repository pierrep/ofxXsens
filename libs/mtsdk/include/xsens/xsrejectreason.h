#ifndef XSREJECTREASON_H
#define XSREJECTREASON_H

#include "xdaconfig.h"

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Identifiers for why a device's connection was rejected. */
enum XsRejectReason
{
	XRR_Unknown = 0,
	XRR_VersionMismatch = 1,
	XRR_Blacklisted = 2,
	XRR_StationIsDisconnecting = 3,
	XRR_SystemIsOperational = 4,
};
/*! @} */
typedef enum XsRejectReason XsRejectReason;

#ifdef __cplusplus
extern "C" {
#endif

XDA_DLL_API const char *XsRejectReason_toString(XsRejectReason r);

#ifdef __cplusplus
} // extern "C"

/*! \brief \copybrief XsRejectReason_toString \sa XsRejectReason_toString */
inline const char *toString(XsRejectReason r)
{
	return XsRejectReason_toString(r);
}
#endif


#endif // file guard
