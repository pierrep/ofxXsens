#ifndef XSOPTION_H
#define XSOPTION_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Xda options, used to control the kind of data processing done by XDA
	\details These options are used to specify whether XDA should compute certain kinds of data from
	available other data.
*/
enum XsOption {
	 XSO_Calibrate		//!< Compute calibrated inertial data from raw data and temperature
	,XSO_Orientation	//!< Compute orientation, requires calibrated data so setting this implies XPO_Calibrate

	,XSO_Count			//!< \private The total number of options, used internally
};
/*! @} */
typedef enum XsOption XsOption;

#endif // file guard
