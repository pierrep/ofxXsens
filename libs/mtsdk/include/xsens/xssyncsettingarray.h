#ifndef XSSYNCSETTINGARRAY_H
#define XSSYNCSETTINGARRAY_H

#include <xsens/xsarray.h>

#ifdef __cplusplus
#include "xssyncsetting.h"
extern "C" {
#endif

extern XsArrayDescriptor const XDA_DLL_API g_xsSyncSettingArrayDescriptor;

#ifndef __cplusplus
#define XSSYNCSETTINGSARRAY_INITIALIZER	XSARRAY_INITIALIZER(&g_xsSyncSettingArrayDescriptor)

struct XsSyncSetting;
XSARRAY_STRUCT(XsSyncSettingArray, struct XsSyncSetting);
typedef struct XsSyncSettingArray XsSyncSettingArray;

XDA_DLL_API void XsSyncSettingArray_construct(XsSyncSettingArray* thisPtr, XsSize count, struct XsSyncSetting const* src);
#else
} // extern "C"
#endif

#ifdef __cplusplus
struct XsSyncSettingArray : public XsArrayImpl<XsSyncSetting, g_xsSyncSettingArrayDescriptor, XsSyncSettingArray> {
	//! \brief Constructs an XsSyncSettingArray
	inline XsSyncSettingArray(XsSize sz = 0, XsSyncSetting const* src = 0)
		 : ArrayImpl(sz, src)
	{
	}

	//! \brief Constructs an XsSyncSettingArray as a copy of \a other
	inline XsSyncSettingArray(XsSyncSettingArray const& other)
		 : ArrayImpl(other)
	{
	}

	//! \brief Constructs an XsSyncSettingArray that references the data supplied in \a ref
	inline explicit XsSyncSettingArray(XsSyncSetting* ref, XsSize sz, XsDataFlags flags = XSDF_None)
		: ArrayImpl(ref, sz, flags)
	{
	}

	//! \brief Constructs an XsSyncSettingArray with the array bound by the supplied iterators \a beginIt and \a endIt
	template <typename Iterator>
	inline XsSyncSettingArray(Iterator beginIt, Iterator endIt)
		: ArrayImpl(beginIt, endIt)
	{
	}
};
#endif
#endif // file guard
