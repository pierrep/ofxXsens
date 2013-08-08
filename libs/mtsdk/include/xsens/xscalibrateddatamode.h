#ifndef XSCALIBRATEDDATAMODE_H
#define XSCALIBRATEDDATAMODE_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Legacy calibrated data output selection flags */
enum XsCalibratedDataMode {
	XCDM_None			= 0,
	XCDM_Acceleration	= (1 << 0),
	XCDM_GyroscopeData	= (1 << 1),
	XCDM_MagneticField	= (1 << 2),

	XCDM_AccGyr = XCDM_Acceleration|XCDM_GyroscopeData,
	XCDM_AccMag = XCDM_Acceleration|XCDM_MagneticField,
	XCDM_GyrMag = XCDM_GyroscopeData|XCDM_MagneticField,

	XCDM_All = XCDM_Acceleration|XCDM_GyroscopeData|XCDM_MagneticField
};
/*! @} */
typedef enum XsCalibratedDataMode XsCalibratedDataMode;

#endif // file guard
