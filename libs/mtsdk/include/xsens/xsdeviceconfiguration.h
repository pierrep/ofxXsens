#ifndef XSDEVICECONFIGURATION_H
#define XSDEVICECONFIGURATION_H

#include "xdaconfig.h"
#include <xsens/pstdint.h>
#include <xsens/xsbusid.h>
#include <xsens/xstypedefs.h>
#ifdef __cplusplus
#include <stdexcept>
#endif

struct MtwInfo;
struct XsDeviceConfiguration;
struct XsMessage;

#ifdef __cplusplus
extern "C" {
#else
#define XSDEVICEINFO_INITIALIZER = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define XSDEVICECONFIGURATION_INITIALIZER = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
typedef struct XsDeviceConfiguration XsDeviceConfiguration;
#endif

XDA_DLL_API	void XsDeviceConfiguration_construct(XsDeviceConfiguration* thisPtr);
XDA_DLL_API	void XsDeviceConfiguration_assign(XsDeviceConfiguration* thisPtr, XsSize numberOfDevices, const XsDeviceConfiguration* src);
XDA_DLL_API	void XsDeviceConfiguration_destruct(XsDeviceConfiguration* thisPtr);
XDA_DLL_API	void XsDeviceConfiguration_copy(XsDeviceConfiguration* copy, XsDeviceConfiguration const* src);
XDA_DLL_API	int  XsDeviceConfiguration_empty(const XsDeviceConfiguration* thisPtr);
XDA_DLL_API void XsDeviceConfiguration_readFromMessage(XsDeviceConfiguration* thisPtr, const struct XsMessage* msg);
XDA_DLL_API	void XsDeviceConfiguration_writeToMessage(const XsDeviceConfiguration* thisPtr, struct XsMessage* msg);

#ifdef __cplusplus
} // extern "C"
#endif

/*! \brief %Device information for MT devices in an XsDeviceConfiguration. */
struct XsMtDeviceConfiguration {
	uint32_t	m_deviceId;			/*!< \brief This device ID */
	uint16_t	m_dataLength;			/*!< \brief The total length of the data */
	uint16_t	m_outputMode;			/*!< \brief The legacy output mode \sa XsOutputMode */
	uint32_t	m_outputSettings;		/*!< \brief The legacy output settings \sa XsOutputSettings */
	uint16_t	m_filterProfile;		/*!< \brief The currently chosen filter profile */
	uint8_t		m_fwRevMajor;			/*!< \brief The major version of the firmware */
	uint8_t		m_fwRevMinor;			/*!< \brief The minor version of the firmware */
	uint8_t		m_fwRevRevision;		/*!< \brief The revision version of the firmware */
	uint8_t		m_filterType;			/*!< \brief The filter type */
	uint8_t		m_filterMajor;			/*!< \brief The filter major version */
	uint8_t		m_filterMinor;			/*!< \brief The filter minor version */
};

typedef struct XsMtDeviceConfiguration XsMtDeviceConfiguration;

/*! \brief Device information for the main device in an XsDeviceConfiguration. */
struct XsMasterDeviceConfiguration {
	uint32_t		m_masterDeviceId;	/*!< \brief The master device ID */
	uint16_t		m_samplingPeriod;	/*!< \brief The sampling period */
	uint16_t		m_outputSkipFactor;	/*!< \brief The output skip factor */
	uint16_t		m_syncInMode;		/*!< \brief The sync-in mode */
	uint16_t		m_syncInSkipFactor;	/*!< \brief The sync-in skip factor */
	uint32_t		m_syncInOffset;		/*!< \brief The sync-in offset */
	uint8_t			m_date[8];		/*!< \brief The date */
	uint8_t			m_time[8];		/*!< \brief The time */
	uint8_t			m_reservedForHost[32];	/*!< \brief Reserved space */
	uint8_t			m_reservedForClient[32];/*!< \brief Reserved space */
};
typedef struct XsMasterDeviceConfiguration XsMasterDeviceConfiguration;

#ifdef __cplusplus
/*! \class XsDeviceConfigurationException
	Exception class thrown when an exception occured inside the XsDeviceConfiguration
*/
class XsDeviceConfigurationException : public std::runtime_error {
public:
	XsDeviceConfigurationException() : std::runtime_error("Invalid device configuration") {}
};
#endif

/*! \brief Structure containing a full device configuration as returned by the ReqConfig message. */
struct XsDeviceConfiguration {
#ifdef __cplusplus
	/*! \brief Constructor
	  
	  \param numberOfDevs : The number of devices for which memory should be allocated in the XsDeviceConfiguration

	  \sa XsDeviceConfiguration_construct
	*/
	XsDeviceConfiguration(uint16_t numberOfDevs = 0)
		: m_numberOfDevices(0)
		, m_deviceInfo(0)
	{
		memset(this, 0, sizeof(XsDeviceConfiguration));
		if (numberOfDevs)
			XsDeviceConfiguration_assign(this, numberOfDevs, 0);
	}

	/*! \brief Copy constructor
	  \param other the object to copy
	  \sa XsDeviceConfiguration_copy
	 */
	XsDeviceConfiguration(const XsDeviceConfiguration& other)
		: m_numberOfDevices(0)
		, m_deviceInfo(0)
	{
		memset(this, 0, sizeof(XsDeviceConfiguration));
		XsDeviceConfiguration_copy(this, &other);
	}
	
	/*! \brief Assign \a other to this device configuaration

	  \param other the object to copy

	  \returns a const reference to this object
	  \sa XsDeviceConfiguration_copy
	 */
	inline const XsDeviceConfiguration& operator = (const XsDeviceConfiguration& other)
	{
		if (this != &other)
			XsDeviceConfiguration_copy(this, &other);
		return *this;
	}

	/*! \brief Destructor \sa XsDeviceConfiguration_destruct */
	inline ~XsDeviceConfiguration()
	{
		XsDeviceConfiguration_destruct(this);
	}

	/*! \brief Clears and frees data \sa XsDeviceConfiguration_destruct */
	inline void clear()
	{
		XsDeviceConfiguration_destruct(this);
	}
	
	/*! \brief Test if this object is empty
	  \returns true if this object is empty
	*/
	inline bool empty() const
	{
		return m_numberOfDevices == 0;
	}

	/*! \brief \copybrief XsDeviceConfiguration_readFromMessage

	   \param msg the message to read the device configuration from

	   \sa XsDeviceConfiguration_readFromMessage
	 */
	inline void readFromMessage(const XsMessage &msg)
	{
		XsDeviceConfiguration_readFromMessage(this, &msg);
	}

	/*! \brief \copybrief XsDeviceConfiguration_writeToMessage

	   \param msg the message to write the device configuration to

	   \sa XsDeviceConfiguration_writeToMessage
	 */
	inline void writeToMessage(XsMessage& msg) const
	{
		XsDeviceConfiguration_writeToMessage(this, &msg);
	}

	/*! \brief The device info for the device at \a busId
	  
	  \param busId the bus ID of the device for which to return data for

	  \returns a reference to the device configuration for the device at \a busId
	*/
	inline XsMtDeviceConfiguration& deviceInfo(uint16_t busId)
	{
		if (!m_numberOfDevices)
			throw XsDeviceConfigurationException();

		//lint --e{613} The check for m_numberOfDevices prevents a NULL pointer in the rest of the function
		if (busId == XS_BID_MASTER)
			return m_deviceInfo[0];

		if (busId > m_numberOfDevices)
			throw XsDeviceConfigurationException();

		return m_deviceInfo[busId-1];
	}

	/*! \brief The device info for the device at \a busId
	  
	  \param busId the bus ID of the device for which to return data for

	  \returns a const reference to the device configuration for the device at \a busId
	*/
	inline const XsMtDeviceConfiguration& deviceInfo(uint16_t busId) const
	{
		if (!m_numberOfDevices)
			throw XsDeviceConfigurationException();

		//lint --e{613} The check for m_numberOfDevices prevents a NULL pointer in the rest of the function
		if (busId == XS_BID_MASTER)
			return m_deviceInfo[0];

		if (busId > m_numberOfDevices)
			throw XsDeviceConfigurationException();

		return m_deviceInfo[busId-1];
	}

	
	/*! \brief The device info for the master device
	  
	  \returns a reference to the device configuration for the master device
	*/
	inline XsMasterDeviceConfiguration& masterInfo()
	{
		//lint --e{1536} intentional low access
		return m_masterInfo;
	}

	/*! \brief The device info for the master device
	  
	  \returns a const reference to the device configuration for the master device
	*/
	inline const XsMasterDeviceConfiguration& masterInfo() const
	{
		return m_masterInfo;
	}

	/*! \brief Set the number of devices to \a count
	  \param count the new number of devices to allocate for
	 */
	inline void setNumberOfDevices(XsSize count)
	{
		XsDeviceConfiguration_assign(this, count, 0);
	}

	/*! \brief The current number of devices
	  \returns the number of devices
	 */
	inline XsSize numberOfDevices() const
	{
		return (XsSize) m_numberOfDevices;
	}

private:
#endif
	XsMasterDeviceConfiguration m_masterInfo;	//!< \brief The master info
	const uint16_t	m_numberOfDevices;		//!< \brief The currently allocated number of devices
	XsMtDeviceConfiguration* const m_deviceInfo;	//!< \brief The list of device infos
};

typedef struct XsDeviceConfiguration XsDeviceConfiguration;

#endif // file guard
