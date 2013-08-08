#ifndef XSQUEUEMODE_H
#define XSQUEUEMODE_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Data queue modes, determine which data to retrieve from the live stream
*/
enum XsQueueMode {
	 XQM_CallbackOnly	//!< Live data is never queued and only available through callbacks. This is the default queue mode.
	,XQM_Fifo			//!< First in - First out. All data is queued and can be retrieved in order of packet ID.
	,XQM_Last			//!< Last data only. Only the latest data is available and remains available at all times.
};
/*! @} */
typedef enum XsQueueMode XsQueueMode;

#endif
