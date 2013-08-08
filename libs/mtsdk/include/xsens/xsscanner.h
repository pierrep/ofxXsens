#ifndef XSSCANNER_H
#define XSSCANNER_H

#include <xsens/xsbaud.h>
struct XsPortInfoArray;
struct XsUsbHubInfo;

#ifdef __cplusplus
#include <xsens/xsportinfoarray.h>
#include "xsusbhubinfo.h"
#include <xsens/xsstring.h>
extern "C" {
#endif
struct XsPortInfo;

XDA_DLL_API void XsScanner_scanPorts(struct XsPortInfoArray* ports, XsBaudRate baudrate, int singleScanTimeout, int ignoreNonXsensDevices);
XDA_DLL_API int XsScanner_scanPort(struct XsPortInfo* port, XsBaudRate baudrate, int singleScanTimeout);
XDA_DLL_API void XsScanner_enumerateSerialPorts(struct XsPortInfoArray* ports, int ignoreNonXsensDevices);
XDA_DLL_API void XsScanner_filterResponsiveDevices(struct XsPortInfoArray* ports, XsBaudRate baudrate, int singleScanTimeout);
XDA_DLL_API void XsScanner_enumerateUsbDevices(struct XsPortInfoArray* ports);
XDA_DLL_API void XsScanner_scanUsbHub(struct XsUsbHubInfo* hub, const struct XsPortInfo* port);
XDA_DLL_API void XsScanner_abortScan(void);

#ifdef __cplusplus
} // extern "C"

class XsScanner {
public:
	/*!	\brief Scan all ports for Xsens devices.
		\param[in] baudrate The baudrate to scan at. When set to XBR_Invalid, all known baudrates are scanned.
		\param[in] singleScanTimeout The timeout of a scan of a single port at a single baud rate in ms.
		\param[in] ignoreNonXsensDevices When true (the default), only Xsens devices are returned. Otherwise other devices that comply with the Xsens message protocol will also be returned.
		\returns The list of detected ports.
		\sa XsScanner_scanPorts
	*/
	static inline XsPortInfoArray scanPorts(XsBaudRate baudrate = XBR_Invalid, int singleScanTimeout = 100, bool ignoreNonXsensDevices = true)
	{
		XsPortInfoArray ports;
		XsScanner_scanPorts(&ports, baudrate, singleScanTimeout, ignoreNonXsensDevices);
		return ports;
	}

	//! \copydoc XsScanner_scanPort
	static inline bool XSNOCOMEXPORT scanPort(XsPortInfo& port, XsBaudRate baudrate = XBR_Invalid, int singleScanTimeout = 100)
	{
		return 0 != XsScanner_scanPort(&port, baudrate, singleScanTimeout);
	}

	/*!	\brief Scan a single port for Xsens devices.
		\param[in] portName The name of the port to scan.
		\param[in] baudrate The baudrate to scan at. When set to XBR_Invalid, all known baudrates are scanned.
		\param[in] singleScanTimeout The timeout of a scan at a single baud rate in ms.
		\returns An XsPortInfo structure with the results of the scan.
		\sa XsScanner_scanPort
	*/
	static inline XsPortInfo scanPort(const XsString& portName, XsBaudRate baudrate = XBR_Invalid, int singleScanTimeout = 100)
	{
		XsPortInfo pi(portName, baudrate);
		if (scanPort(pi, baudrate, singleScanTimeout))
			return pi;

		return XsPortInfo();
	}

	/*!	\brief List all serial ports without scanning
		\param ignoreNonXsensDevices When true (the default), only Xsens ports are returned.
		\returns The list of detected ports.
	*/
	static inline XsPortInfoArray enumerateSerialPorts(bool ignoreNonXsensDevices = true)
	{
		XsPortInfoArray ports;
		XsScanner_enumerateSerialPorts(&ports, ignoreNonXsensDevices);
		return ports;
	}
	
	/*!	\brief Scan the supplied ports for Xsens devices.
		\details This function does not modify the input list as opposed to XsScanner_filterResponsiveDevices
		\param[in] ports The list of ports to scan.
		\param[in] baudrate The baudrate to scan at. When set to XBR_Invalid, all known baudrates are scanned.
		\param[in] singleScanTimeout The timeout of a scan of a single port at a single baud rate in ms.
		\returns The list of ports that have responsive devices on them.
		\sa XsScanner_filterResponsiveDevices
	*/
	static inline XsPortInfoArray filterResponsiveDevices(const XsPortInfoArray& ports, XsBaudRate baudrate = XBR_Invalid, int singleScanTimeout = 100)
	{
		XsPortInfoArray filtered(ports);
		XsScanner_filterResponsiveDevices(&filtered, baudrate, singleScanTimeout);
		return filtered;
	}

	/*!	\brief List all compatible USB ports without scanning.
		\returns The list of detected usb devices.
		\sa XsScanner_enumerateUsbDevices
	*/
	static inline XsPortInfoArray enumerateUsbDevices(void)
	{
		XsPortInfoArray ports;
		XsScanner_enumerateUsbDevices(&ports);
		return ports;
	}

	/*!	\brief Determine the USB hub that \a port is attached to
		\param port The port for which to determine the USB hub.
		\returns The identifier of the hub that \a port is attached to.
		\sa XsScanner_scanUsbHub
	*/
	static inline XsUsbHubInfo scanUsbHub(const XsPortInfo& port)
	{
		XsUsbHubInfo hub;
		XsScanner_scanUsbHub(&hub, &port);
		return hub;
	}

	//! \copydoc XsScanner_abortScan
	static inline void abortScan(void)
	{
		XsScanner_abortScan();
	}
};

#endif

#endif // file guard
