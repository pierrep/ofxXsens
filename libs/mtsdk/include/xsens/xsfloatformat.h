#ifndef XSFLOATFORMAT_H
#define XSFLOATFORMAT_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Legacy floating point / fixed point format options */
enum XsFloatFormat {
	FF_IEEE754Float,		//!< Single precision floating point (IEEE 754)
	FF_FixedPoint1220,		//!< Fixed point 12.20 format (12 signed bits before decimal, 20 after)
	FF_FixedPoint1632		//!< Fixed point 16.32 format (16 signed bits before decimal, 32 after)
};
/*! @} */
typedef enum XsFloatFormat XsFloatFormat;

#endif // file guard
