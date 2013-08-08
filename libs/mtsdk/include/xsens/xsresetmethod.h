#ifndef XSRESETMETHOD_H
#define XSRESETMETHOD_H

/*!	\addtogroup enums Global enumerations
	@{
*/
/*! \brief Orientation reset type. */
enum XsResetMethod {
	XRM_StoreAlignmentMatrix	= 0,				//!< \brief Store the current object alignment matrix to persistent memory
	XRM_Heading					= 1,				//!< \brief Reset the heading (yaw)
	XRM_Object					= 3,				//!< \brief Reset the attitude (roll, pitch), same as XRM_Inclination
	XRM_Inclination				= XRM_Object,		//!< \brief Reset the inclination (roll, pitch), same as XRM_Object
	XRM_Alignment				= 4,				//!< \brief Reset heading and attitude \details This effectively combines the XRM_Heading and XRM_Object
	XRM_Global					= XRM_Alignment,	//!< \brief Reset the full orientation of the device \details Obsolete. Use XRM_Alignment instead.
	XRM_DefaultHeading			= 5,				//!< \brief Revert to default behaviour for heading, undoes XRM_Heading
	XRM_DefaultInclination		= 6,				//!< \brief Revert to default behaviour for inclination, undoes XRM_Inclination
	XRM_DefaultAlignment		= 7,				//!< \brief Revert to default behaviour for heading and inclination, undoes any reset
	XRM_None										//!< \brief No reset planned
};
/*! @} */
typedef enum XsResetMethod XsResetMethod;

#endif // file guard
