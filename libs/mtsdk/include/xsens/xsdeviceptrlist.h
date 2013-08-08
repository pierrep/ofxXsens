#ifndef XSDEVICEPTRLIST_H
#define XSDEVICEPTRLIST_H

#include "xsdeviceptrarray.h"
#define XsDevicePtrList XsDevicePtrArray

#ifndef __cplusplus

#define XSDEVICEPTRLIST_INITIALIZER		XSDEVICEPTRARRAY_INITIALIZER

#define XsDevicePtrList_assign(thisPtr, size, src)		XsArray_assign(thisPtr, size, src)
#define XsDevicePtrList_construct(thisPtr, size, src)	XsDevicePtrArray_construct(thisPtr, size, src)
#define XsDevicePtrList_destruct(thisPtr)				XsArray_destruct(thisPtr)
#define XsDevicePtrList_copy(thisPtr, copy)				XsArray_copy(copy, thisPtr)
#define XsDevicePtrList_append(thisPtr, other)			XsArray_append(thisPtr, other)
#define XsDevicePtrList_popFront(thisPtr, count)		XsArray_erase(thisPtr, 0, count)
#define XsDevicePtrList_popBack(thisPtr, count)			XsArray_erase(thisPtr, (XsSize)-1, count)
#define XsDevicePtrList_swap(a, b)						XsArray_swap(a, b)
#define XsDevicePtrList_erase(thisPtr, index, count)	XsArray_erase(thisPtr, index, count)

#endif
#endif // file guard
