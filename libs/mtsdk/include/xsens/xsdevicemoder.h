#ifndef XSDEVICEMODER_H
#define XSDEVICEMODER_H

#include "xdaconfig.h"
#include <xsens/pstdint.h>
#include <xsens/xsdataformat.h>

#define XS_DEFAULT_UPDATE_RATE			100

struct XsDeviceModeR;

#ifdef __cplusplus
extern "C" {
#endif

XDA_DLL_API int XsDeviceModeR_updateRate(const struct XsDeviceModeR* thisPtr);
XDA_DLL_API void XsDeviceModeR_getPeriodAndSkipFactor(const struct XsDeviceModeR* thisPtr, uint16_t* period, uint16_t* skip);
XDA_DLL_API void XsDeviceModeR_setPeriodAndSkipFactor(struct XsDeviceModeR* thisPtr, uint16_t period, uint16_t skip);

#ifdef __cplusplus
} // extern "C"
#endif


/*! \brief A structure for storing device modes. */
struct XsDeviceModeR {
	XsOutputMode		m_outputMode;		//!< The output mode
	XsOutputSettings	m_outputSettings;	//!< The output settings
	uint16_t			m_updateRate;		//!< The desired update rate

#ifdef __cplusplus
	//! default constructor, initializes to the given (default) MT settings
	XsDeviceModeR(	const XsOutputMode mode = XS_DEFAULT_OUTPUT_MODE,
					const XsOutputSettings settings = XS_DEFAULT_OUTPUT_SETTINGS,
					const uint16_t rate = XS_DEFAULT_UPDATE_RATE)
	: m_outputMode(mode), m_outputSettings(settings), m_updateRate(rate)
	{}

	/*! \copydoc XsDeviceModeR_updateRate */
	inline int updateRate(void) const
	{
		return XsDeviceModeR_updateRate(this);
	}

	/*! \copydoc XsDeviceModeR_getPeriodAndSkipFactor */
	inline void getPeriodAndSkipFactor(uint16_t& period, uint16_t& skip) const
	{
		XsDeviceModeR_getPeriodAndSkipFactor(this, &period, &skip);
	}

	/*! \copydoc XsDeviceModeR_setPeriodAndSkipFactor */
	inline void setPeriodAndSkipFactor(uint16_t period, uint16_t skip)
	{
		XsDeviceModeR_setPeriodAndSkipFactor(this, period, skip);
	}

	//! \brief Check if all fields of the two structures are equal
	inline bool operator == (const XsDeviceModeR& dev) const
	{
		return	m_outputMode == dev.m_outputMode &&
				m_outputSettings == dev.m_outputSettings &&
				m_updateRate == dev.m_updateRate;
	}
#endif
};
typedef struct XsDeviceModeR XsDeviceModeR;

#endif // file guard
