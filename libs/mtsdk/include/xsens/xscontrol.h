#ifndef GUARD_XSCONTROL_H
#define GUARD_XSCONTROL_H
#include <xsens/pstdint.h>
#include <xsens/xstypedefs.h>
#include "xsstring.h"
#include "xsversion.h"
#include "xsdeviceconfiguration.h"
#include "xsdevicemode.h"
#include "xsfilterprofile.h"
#include "xsportinfo.h"
#include "xsportinfoarray.h"
#include "xssyncsetting.h"
#include "xsdatapacket.h"
#include "xsmessage.h"
#include "xsdeviceptrarray.h"
#include "xsresultvalue.h"
#include "xsbaud.h"
#include "xsxbusmessageid.h"
#include "xsqueuemode.h"
#include "xsdeviceidarray.h"
#include "xsintlist.h"
#include "xssyncsettingarray.h"
#include "xsfilterprofilearray.h"
#include "xsdevice.h"
#include "xsfilepos.h"
#include "xsoption.h"
#ifdef __cplusplus
extern "C" {
#endif
/*! \addtogroup cinterface C Interface
	@{ */
struct XsControl;
typedef struct XsControl XsControl;
XDA_DLL_API struct XsControl* XsControl_construct(void);//!< \copydoc XsControl::XsControl() \returns The newly constructed object
XDA_DLL_API void XsControl_destruct(struct XsControl* thisPtr);//!< \copydoc XsControl::~XsControl() 
XDA_DLL_API int XsControl_setSerialKey(const XsString* key);//!< \copydoc XsControl::setSerialKey(const XsString&) 
XDA_DLL_API void XsControl_flushInputBuffers(struct XsControl* thisPtr, int complete);//!< \copydoc XsControl::flushInputBuffers(bool) 
XDA_DLL_API XsVersion* XsControl_version(XsVersion* returnValue);//!< \copydoc XsControl::version() 
XDA_DLL_API XsString* XsControl_libraryPath(XsString* returnValue);//!< \copydoc XsControl::libraryPath() 
XDA_DLL_API XsString* XsControl_resultText(XsString* returnValue, XsResultValue resultCode);//!< \copydoc XsControl::resultText(XsResultValue) 
XDA_DLL_API void XsControl_setLogPath(const XsString* path);//!< \copydoc XsControl::setLogPath(const XsString&) 
XDA_DLL_API void XsControl_close(struct XsControl* thisPtr);//!< \copydoc XsControl::close() 
XDA_DLL_API int XsControl_openPort(struct XsControl* thisPtr, const XsString* portname, XsBaudRate baudrate, uint32_t timeout);//!< \copydoc XsControl::openPort(const XsString&,XsBaudRate,uint32_t) 
XDA_DLL_API int XsControl_openPort_1(struct XsControl* thisPtr, const XsPortInfo* portinfo, uint32_t timeout);//!< \copydoc XsControl::openPort(const XsPortInfo&,uint32_t) 
XDA_DLL_API int XsControl_openImarPort_internal(struct XsControl* thisPtr, const XsString* portname, XsBaudRate baudrate, int imarType, uint32_t timeout);//!< \private
XDA_DLL_API void XsControl_closePort(struct XsControl* thisPtr, const XsString* portname);//!< \copydoc XsControl::closePort(const XsString&) 
XDA_DLL_API void XsControl_closePort_1(struct XsControl* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsControl::closePort(const XsDeviceId&) 
XDA_DLL_API void XsControl_closePort_2(struct XsControl* thisPtr, const XsPortInfo* portinfo);//!< \copydoc XsControl::closePort(const XsPortInfo&) 
XDA_DLL_API int XsControl_openLogFile(struct XsControl* thisPtr, const XsString* filename);//!< \copydoc XsControl::openLogFile(const XsString&) 
XDA_DLL_API XsResultValue XsControl_lastResult(const struct XsControl* thisPtr);//!< \copydoc XsControl::lastResult() const 
XDA_DLL_API XsString* XsControl_lastResultText(const struct XsControl* thisPtr, XsString* returnValue);//!< \copydoc XsControl::lastResultText() const 
XDA_DLL_API int XsControl_deviceCount(const struct XsControl* thisPtr);//!< \copydoc XsControl::deviceCount() const 
XDA_DLL_API int XsControl_mainDeviceCount(const struct XsControl* thisPtr);//!< \copydoc XsControl::mainDeviceCount() const 
XDA_DLL_API XsDeviceIdArray* XsControl_mainDeviceIds(const struct XsControl* thisPtr, XsDeviceIdArray* returnValue);//!< \copydoc XsControl::mainDeviceIds() const 
XDA_DLL_API int XsControl_mtCount(const struct XsControl* thisPtr);//!< \copydoc XsControl::mtCount() const 
XDA_DLL_API XsDeviceIdArray* XsControl_mtDeviceIds(const struct XsControl* thisPtr, XsDeviceIdArray* returnValue);//!< \copydoc XsControl::mtDeviceIds() const 
XDA_DLL_API XsDeviceIdArray* XsControl_deviceIds(const struct XsControl* thisPtr, XsDeviceIdArray* returnValue);//!< \copydoc XsControl::deviceIds() const 
XDA_DLL_API XsDeviceId* XsControl_getDeviceIdFromLocationId(const struct XsControl* thisPtr, XsDeviceId* returnValue, uint16_t locationId);//!< \copydoc XsControl::getDeviceIdFromLocationId(uint16_t) const 
XDA_DLL_API XsDeviceId* XsControl_dockDeviceId(const struct XsControl* thisPtr, XsDeviceId* returnValue, const XsDeviceId* deviceId);//!< \copydoc XsControl::dockDeviceId(const XsDeviceId&) const 
XDA_DLL_API int XsControl_isDeviceWireless(const struct XsControl* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsControl::isDeviceWireless(const XsDeviceId&) const 
XDA_DLL_API int XsControl_isDeviceDocked(const struct XsControl* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsControl::isDeviceDocked(const XsDeviceId&) const 
XDA_DLL_API void XsControl_setQueueMode(struct XsControl* thisPtr, XsQueueMode mode);//!< \copydoc XsControl::setQueueMode(XsQueueMode) 
XDA_DLL_API XsQueueMode XsControl_queueMode(const struct XsControl* thisPtr);//!< \copydoc XsControl::queueMode() const 
XDA_DLL_API int XsControl_loadFilterProfiles(struct XsControl* thisPtr, const XsString* filename);//!< \copydoc XsControl::loadFilterProfiles(const XsString&) 
XDA_DLL_API void XsControl_setOptionEnabled(struct XsControl* thisPtr, XsOption option, int enabled);//!< \copydoc XsControl::setOptionEnabled(XsOption,bool) 
XDA_DLL_API int XsControl_isOptionEnabled(const struct XsControl* thisPtr, XsOption option);//!< \copydoc XsControl::isOptionEnabled(XsOption) const 
XDA_DLL_API int XsControl_setLatLonAlt(struct XsControl* thisPtr, const XsVector* lla);//!< \copydoc XsControl::setLatLonAlt(const XsVector&) 
XDA_DLL_API XsDevice* XsControl_device(const struct XsControl* thisPtr, const XsDeviceId* deviceId);//!< \copydoc XsControl::device(const XsDeviceId&) const 
XDA_DLL_API XsDevicePtrArray* XsControl_mainDevices(const struct XsControl* thisPtr, XsDevicePtrArray* returnValue);//!< \copydoc XsControl::mainDevices() const 
XDA_DLL_API XsDevice* XsControl_broadcast(const struct XsControl* thisPtr);//!< \copydoc XsControl::broadcast() const 
XDA_DLL_API XsResultValue XsControl_testSynchronization(struct XsControl* thisPtr);//!< \copydoc XsControl::testSynchronization() 
XDA_DLL_API void XsControl_clearCallbackHandlers(struct XsControl* thisPtr, int chain);//!< \copydoc XsControl::clearCallbackHandlers(bool) 
XDA_DLL_API void XsControl_addCallbackHandler(struct XsControl* thisPtr, XsCallbackPlainC* cb, int chain);//!< \copydoc XsControl::addCallbackHandler(XsCallbackPlainC*,bool) 
XDA_DLL_API void XsControl_removeCallbackHandler(struct XsControl* thisPtr, XsCallbackPlainC* cb, int chain);//!< \copydoc XsControl::removeCallbackHandler(XsCallbackPlainC*,bool) 
/*! @} */
#ifdef __cplusplus
} // extern "C"
struct XsControl {
	//! \brief Construct a new XsControl* object. Clean it up with the destruct() function
	inline static XsControl* construct(void)
	{
		return XsControl_construct();
	}

	//! \brief Destruct a XsControl object and free all memory allocated for it
	inline void destruct(void)
	{
		XsControl_destruct(this);
	}

	inline static bool setSerialKey(const XsString& key)
	{
		return 0 != XsControl_setSerialKey(&key);
	}

	inline void flushInputBuffers(bool complete)
	{
		XsControl_flushInputBuffers(this, complete);
	}

	inline static XsVersion version(void)
	{
		XsVersion returnValue;
		return *XsControl_version(&returnValue);
	}

	inline static XsString libraryPath(void)
	{
		XsString returnValue;
		return *XsControl_libraryPath(&returnValue);
	}

	inline static XsString resultText(XsResultValue resultCode)
	{
		XsString returnValue;
		return *XsControl_resultText(&returnValue, resultCode);
	}

	inline static void setLogPath(const XsString& path)
	{
		XsControl_setLogPath(&path);
	}

	inline void close(void)
	{
		XsControl_close(this);
	}

	inline bool openPort(const XsString& portname, XsBaudRate baudrate, uint32_t timeout = 0)
	{
		return 0 != XsControl_openPort(this, &portname, baudrate, timeout);
	}

	inline bool openPort(const XsPortInfo& portinfo, uint32_t timeout = 0)
	{
		return 0 != XsControl_openPort_1(this, &portinfo, timeout);
	}

	//! \private
	inline bool openImarPort_internal(const XsString& portname, XsBaudRate baudrate, int imarType, uint32_t timeout = 0)
	{
		return 0 != XsControl_openImarPort_internal(this, &portname, baudrate, imarType, timeout);
	}

	inline void closePort(const XsString& portname)
	{
		XsControl_closePort(this, &portname);
	}

	inline void closePort(const XsDeviceId& deviceId)
	{
		XsControl_closePort_1(this, &deviceId);
	}

	inline void closePort(const XsPortInfo& portinfo)
	{
		XsControl_closePort_2(this, &portinfo);
	}

	inline bool openLogFile(const XsString& filename)
	{
		return 0 != XsControl_openLogFile(this, &filename);
	}

	inline XsResultValue lastResult(void) const
	{
		return XsControl_lastResult(this);
	}

	inline XsString lastResultText(void) const
	{
		XsString returnValue;
		return *XsControl_lastResultText(this, &returnValue);
	}

	inline int deviceCount(void) const
	{
		return XsControl_deviceCount(this);
	}

	inline int mainDeviceCount(void) const
	{
		return XsControl_mainDeviceCount(this);
	}

	inline XsDeviceIdArray mainDeviceIds(void) const
	{
		XsDeviceIdArray returnValue;
		return *XsControl_mainDeviceIds(this, &returnValue);
	}

	inline int mtCount(void) const
	{
		return XsControl_mtCount(this);
	}

	inline XsDeviceIdArray mtDeviceIds(void) const
	{
		XsDeviceIdArray returnValue;
		return *XsControl_mtDeviceIds(this, &returnValue);
	}

	inline XsDeviceIdArray deviceIds(void) const
	{
		XsDeviceIdArray returnValue;
		return *XsControl_deviceIds(this, &returnValue);
	}

	inline XsDeviceId getDeviceIdFromLocationId(uint16_t locationId) const
	{
		XsDeviceId returnValue;
		return *XsControl_getDeviceIdFromLocationId(this, &returnValue, locationId);
	}

	inline XsDeviceId dockDeviceId(const XsDeviceId& deviceId) const
	{
		XsDeviceId returnValue;
		return *XsControl_dockDeviceId(this, &returnValue, &deviceId);
	}

	inline bool isDeviceWireless(const XsDeviceId& deviceId) const
	{
		return 0 != XsControl_isDeviceWireless(this, &deviceId);
	}

	inline bool isDeviceDocked(const XsDeviceId& deviceId) const
	{
		return 0 != XsControl_isDeviceDocked(this, &deviceId);
	}

	inline void setQueueMode(XsQueueMode mode)
	{
		XsControl_setQueueMode(this, mode);
	}

	inline XsQueueMode queueMode(void) const
	{
		return XsControl_queueMode(this);
	}

	inline bool loadFilterProfiles(const XsString& filename)
	{
		return 0 != XsControl_loadFilterProfiles(this, &filename);
	}

	inline void setOptionEnabled(XsOption option, bool enabled)
	{
		XsControl_setOptionEnabled(this, option, enabled);
	}

	inline bool isOptionEnabled(XsOption option) const
	{
		return 0 != XsControl_isOptionEnabled(this, option);
	}

	inline bool setLatLonAlt(const XsVector& lla)
	{
		return 0 != XsControl_setLatLonAlt(this, &lla);
	}

	inline XsDevice* device(const XsDeviceId& deviceId) const
	{
		return XsControl_device(this, &deviceId);
	}

	inline XsDevicePtrArray mainDevices(void) const
	{
		XsDevicePtrArray returnValue;
		return *XsControl_mainDevices(this, &returnValue);
	}

	inline XsDevice* broadcast(void) const
	{
		return XsControl_broadcast(this);
	}

	inline XsResultValue testSynchronization(void)
	{
		return XsControl_testSynchronization(this);
	}

	inline void clearCallbackHandlers(bool chain = true)
	{
		XsControl_clearCallbackHandlers(this, chain);
	}

	inline void addCallbackHandler(XsCallbackPlainC* cb, bool chain = true)
	{
		XsControl_addCallbackHandler(this, cb, chain);
	}

	inline void removeCallbackHandler(XsCallbackPlainC* cb, bool chain = true)
	{
		XsControl_removeCallbackHandler(this, cb, chain);
	}

	//! \brief Destructor, calls destruct() function to clean up object
	~XsControl()
	{
		XsControl_destruct(this);
	}

	//! \protectedsection \brief overloaded delete operator to allow user to use delete instead of calling destruct() function
	void operator delete (void*)
	{
	}

private:
	XsControl(); //!< \protectedsection \brief Default constructor not implemented to prevent faulty memory allocation, use construct() function instead
	void* operator new (size_t); //!< \protectedsection \brief new operator not implemented to prevent faulty memory allocation by user, use construct() function instead
	void* operator new[] (size_t); //!< \protectedsection \brief array new operator not implemented to prevent faulty memory allocation by user, use construct() function instead
	void operator delete[] (void*); //!< \protectedsection \brief array delete operator not implemented to prevent faulty memory deallocation by user, use destruct() function instead
};
#endif // __cplusplus
#endif // GUARD_XSCONTROL_H
