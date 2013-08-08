#ifndef XSDEVICEPTRARRAY_H
#define XSDEVICEPTRARRAY_H

#include <xsens/xsarray.h>
#include "xsdeviceptr.h"

#ifdef __cplusplus
extern "C" {
#endif

extern XsArrayDescriptor const XDA_DLL_API g_xsDevicePtrArrayDescriptor;

#ifndef __cplusplus
#define XSDEVICEPTRARRAY_INITIALIZER	XSARRAY_INITIALIZER(&g_xsDevicePtrArrayDescriptor)

XSARRAY_STRUCT(XsDevicePtrArray, XsDevicePtr);
typedef struct XsDevicePtrArray XsDevicePtrArray;

XDA_DLL_API void XsDevicePtrArray_construct(XsDevicePtrArray* thisPtr, XsSize count, XsDevicePtr const* src);
#else
} // extern "C"
#endif

#ifdef __cplusplus
struct XsDevicePtrArray : public XsArrayImpl<XsDevicePtr , g_xsDevicePtrArrayDescriptor, XsDevicePtrArray> {
	//! \brief Constructs an XsDevicePtrArray
	inline XsDevicePtrArray(XsSize sz = 0, XsDevicePtr const* src = 0)
		 : ArrayImpl(sz, src)
	{
	}

	//! \brief Constructs an XsDevicePtrArray as a copy of \a other
	inline XsDevicePtrArray(XsDevicePtrArray const& other)
		 : ArrayImpl(other)
	{
	}

	//! \brief Constructs an XsDevicePtrArray that references the data supplied in \a ref
	inline explicit XsDevicePtrArray(XsDevicePtr* ref, XsSize sz, XsDataFlags flags = XSDF_None)
		: ArrayImpl(ref, sz, flags)
	{
	}

	//! \brief Constructs an XsDevicePtrArray with the array bound by the supplied iterators \a beginIt and \a endIt
	template <typename Iterator>
	inline XsDevicePtrArray(Iterator beginIt, Iterator endIt)
		: ArrayImpl(beginIt, endIt)
	{
	}
}; //lint !e1509 base class destructor for class 'XsArrayImpl' is not virtual. Cannot be virtual because of needed C compatibility
#endif
#endif // file guard
