#ifndef XSDEVICEMODEPS_H
#define XSDEVICEMODEPS_H

#include "xdaconfig.h"
#include <xsens/pstdint.h>
#include <xsens/xsoutputmode.h>
#include <xsens/xsoutputsettings.h>

#define XS_DEFAULT_PERIOD			1152
#define XS_DEFAULT_SKIP				0

struct XsDeviceModePS;

#ifdef __cplusplus
extern "C" {
#endif

XDA_DLL_API int XsDeviceModePS_updateRate(const struct XsDeviceModePS* thisPtr);
XDA_DLL_API void XsDeviceModePS_setUpdateRate(struct XsDeviceModePS* thisPtr, int rate);

#ifdef __cplusplus
} // extern "C"
#endif

struct XsDeviceModePS {
	XsOutputMode		m_outputMode;		//!< The output mode
	XsOutputSettings	m_outputSettings;	//!< The output settings
	uint16_t			m_period;			//!< The sample period in 1/115200 seconds
	uint16_t			m_skip;				//!< The output skip factor

#ifdef __cplusplus
	//! default constructor, initializes to the given (default) MT settings
	XsDeviceModePS(	const XsOutputMode mode = XS_DEFAULT_OUTPUT_MODE,
					const XsOutputSettings settings = XS_DEFAULT_OUTPUT_SETTINGS,
					const uint16_t period = XS_DEFAULT_PERIOD,
					const uint16_t skip = XS_DEFAULT_SKIP)
	: m_outputMode(mode), m_outputSettings(settings), m_period(period), m_skip(skip)
	{}

	/*! \copydoc XsDeviceModePS_updateRate */
	inline int updateRate(void) const
	{
		return XsDeviceModePS_updateRate(this);
	}

	/*! \copydoc XsDeviceModePS_setUpdateRate */
	inline void setUpdateRate(int rate)
	{
		XsDeviceModePS_setUpdateRate(this, rate);
	}

	//! \brief Check if all fields of the two structures are equal
	inline bool operator == (const XsDeviceModePS& dev) const
	{
		return	m_outputMode == dev.m_outputMode &&
				m_outputSettings == dev.m_outputSettings &&
				m_period == dev.m_period &&
				m_skip == dev.m_skip;
	}
#endif
};
typedef struct XsDeviceModePS XsDeviceModePS;

#endif // file guard
