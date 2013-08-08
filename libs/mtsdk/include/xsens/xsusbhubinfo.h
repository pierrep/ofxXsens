#ifndef XSUSBHUBINFO_H
#define XSUSBHUBINFO_H

#ifdef _WIN32
	typedef int XsHubIdentifier;
#else
	typedef const char* XsHubIdentifier;
#endif

struct XsUsbHubInfo;
#ifndef __cplusplus
#define XSUSBHUBINFO_INITIALIZER { 0 }
typedef struct XsUsbHubInfo XsUsbHubInfo;
#else
extern "C" {
#endif

XDA_DLL_API void XsUsbHubInfo_assign(XsUsbHubInfo* thisPtr, XsHubIdentifier hub);
XDA_DLL_API void XsUsbHubInfo_construct(XsUsbHubInfo* thisPtr, XsHubIdentifier hub);
XDA_DLL_API void XsUsbHubInfo_destruct(XsUsbHubInfo* thisPtr);
XDA_DLL_API void XsUsbHubInfo_copy(XsUsbHubInfo* copy, XsUsbHubInfo const* src);
XDA_DLL_API void XsUsbHubInfo_swap(XsUsbHubInfo* thisPtr, XsUsbHubInfo* thatPtr);
XDA_DLL_API int XsUsbHubInfo_parentPathMatches(const XsUsbHubInfo* thisPtr, const XsUsbHubInfo* other);

#ifdef __cplusplus
} // extern "C"
#endif


/*! \struct XsUsbHubInfo
	\brief A structure that wraps USB hub information
*/
struct XsUsbHubInfo {
#ifdef __cplusplus
	/*! \brief Default constructor

	  \param hubid an optional hub identifier to initialize with
	  \sa XsUsbHubInfo_construct
	 */
	explicit XsUsbHubInfo(XsHubIdentifier hubid = 0)
		: m_hub(0)
	{
		if (hubid)
			XsUsbHubInfo_construct(this, hubid);
	}

	/*! \brief Destructor \sa XsUsbHubInfo_destruct */
	~XsUsbHubInfo()
	{
		XsUsbHubInfo_destruct(this);	//lint !e1551
	}

	/*! \brief Copy constructor
	  \param other the object to copy
	  \sa XsUsbHubInfo_copy \sa XsUsbHubInfo_construct
	 */
	XsUsbHubInfo(const XsUsbHubInfo &other)
		: m_hub(0)
	{
		if (other.m_hub)
			XsUsbHubInfo_construct(this, other.m_hub);
	}

	/*! \brief Assigns \a other to this XsUsbHubInfo
	   \param other the object to copy
	   \returns a const reference to this info object
	   \sa XsUsbHubInfo_copy
	 */
	const XsUsbHubInfo& operator=(const XsUsbHubInfo &other)
	{
		if (this != &other)
			XsUsbHubInfo_copy(this, &other);
		return *this;
	}

	/*! \brief \copybrief XsUsbHubInfo_parentPathMatches
	 * \param other the object to compare to
	 * \returns true if the two objects share the same immediate parent hub, false otherwise
	 * \sa XsUsbHubInfo_parentPathMatches
	 */
	bool parentPathMatches(const XsUsbHubInfo &other) const
	{
		return 0 != XsUsbHubInfo_parentPathMatches(this, &other);
	}

	/*! \brief Returns true if a valid hub is set
	*/
	bool isValid() const
	{
		return m_hub != 0;
	}

	/*! \brief Return the hub identifier
	*/
	inline XsHubIdentifier hub() const
	{
		return m_hub;
	}

private:
#endif
	XsHubIdentifier m_hub;
};
typedef struct XsUsbHubInfo XsUsbHubInfo;

#endif	// file guard
