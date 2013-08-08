#ifndef XSORIENTATIONMODE_H
#define XSORIENTATIONMODE_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Legacy orientation output mode selection
*/
enum XsOrientationMode {
	OM_None,
	OM_Euler,
	OM_Quaternion,
	OM_Matrix
};
/*! @} */
typedef enum XsOrientationMode XsOrientationMode;

#endif // file guard
