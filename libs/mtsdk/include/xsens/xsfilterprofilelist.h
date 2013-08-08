#ifndef XSFILTERPROFILELIST_H
#define XSFILTERPROFILELIST_H

#include "xsfilterprofilearray.h"
#define XsFilterProfileList XsFilterProfileArray

#ifndef __cplusplus

#define XSFILTERPROFILELIST_INITIALIZER		XSFILTERPROFILEARRAY_INITIALIZER

#define XsFilterProfileList_assign(thisPtr, size, src)		XsArray_assign(thisPtr, size, src)
#define XsFilterProfileList_construct(thisPtr, size, src)	XsFilterProfileArray_construct(thisPtr, size, src)
#define XsFilterProfileList_destruct(thisPtr)				XsArray_destruct(thisPtr)
#define XsFilterProfileList_copy(thisPtr, copy)				XsArray_copy(copy, thisPtr)
#define XsFilterProfileList_append(thisPtr, other)			XsArray_append(thisPtr, other)
#define XsFilterProfileList_popFront(thisPtr, count)		XsArray_erase(thisPtr, 0, count)
#define XsFilterProfileList_popBack(thisPtr, count)			XsArray_erase(thisPtr, (XsSize)-1, count)
#define XsFilterProfileList_swap(a, b)						XsArray_swap(a, b)
#define XsFilterProfileList_erase(thisPtr, index, count)	XsArray_erase(thisPtr, index, count)

#endif
#endif // file guard
