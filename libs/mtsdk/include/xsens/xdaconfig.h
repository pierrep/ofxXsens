// include this file in Visual Studio using C/C++->Advanced->Force Includes (the /FI option)
#ifndef XDA_CONFIG_H
#define XDA_CONFIG_H

//////////////////////////////////////////////////
// generic preprocessor defines

// make sure both _WIN32 and WIN32 are defined if either of them is.
#if defined(_WIN32) || defined(_M_IX86)
#	ifndef WIN32
#		define WIN32
#	endif
#	define XSENS_WINDOWS
#endif

#ifdef WIN32
#	ifndef _WIN32
#		define _WIN32
#		define XSENS_WINDOWS
#	endif
#endif

// make things as secure as possible without modifying the code...
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifdef __GNUC__
#include <limits.h>
#if __WORDSIZE == 64
#	define XSENS_64BIT
#else
#	define XSENS_32BIT
#endif
#endif

#if defined(_WIN64) || defined(_M_X64) || defined(_M_IA64)
#	ifndef XSENS_64BIT
#		define XSENS_64BIT
#	endif
#	ifndef XSENS_WINDOWS
#		define XSENS_WINDOWS
#	endif
#	ifndef WIN64
#		define WIN64
#	endif
#else
#	ifndef XSENS_32BIT
#		define XSENS_32BIT
#	endif
#endif

// all xsens libraries should use unicode
#ifndef UNICODE
#define UNICODE
#endif

// use XSENS_32BIT and XSENS_64BIT to check for 32/64 bit builds in your application
// on non-windows systems these should be defined in this file

/*
Configuration | Runtime | DebInfo | Defines
--------------+---------------------------------------
Debug         | MDd     | Yes     | XSENS_DEBUG;_DEBUG
RelWithDeb    | MD      | Yes     | XSENS_DEBUG;XSENS_RELEASE;NDEBUG
Release       | MD      | No      | XSENS_RELEASE;NDEBUG

The common way to setup configuration-dependent defines:
#if defined(XSENS_DEBUG)
	//// Debug or RelWithDeb build
	#if defined(XSENS_RELEASE)
		//// RelWithDeb build
	#else
		//// Debug build
	#endif
#else
	//// Release build
#endif
*/

#if defined(XSENS_DEBUG)
	//// Debug or RelWithDeb build

	#if defined(XSENS_RELEASE)
		//// RelWithDeb build
		#if !defined(QT_DEBUG) && !defined(QT_NO_DEBUG)
		#define QT_NO_DEBUG	1
		#endif
	#else
		//// Debug build
		#if !defined(QT_DEBUG) && !defined(QT_NO_DEBUG)
		#define QT_DEBUG	1
		#endif
	#endif
#else
	//// Release build
	#if !defined(QT_DEBUG) && !defined(QT_NO_DEBUG)
	#define QT_NO_DEBUG	1
	#endif
#endif

//////////////////////////////////////////////////
// more generic preprocessor defines

//////////////////////////////////////////////////
// generic preprocessor defines

// use XSENS_32BIT and XSENS_64BIT to check for 32/64 bit builds in your application
// on non-windows systems these should be defined

#ifndef XDA_DLL_API
#	ifdef XDA_DLL_EXPORT
#		ifdef _WIN32
//#			pragma message("XDA_DLL_API export in xstypesconfig.h")
#			define XDA_DLL_API __declspec(dllexport)
#		else
//#			pragma message("XDA_DLL_API linux export in xstypesconfig.h")
#			define XDA_DLL_API __attribute__((visibility("default")))
#		endif
#	else	// ifdef XDA_DLL_EXPORT
#		ifdef XDA_STATIC_LIB
//#			pragma message("XDA_DLL_API static in xstypesconfig.h")
#			define XDA_DLL_API
#		else
#			ifdef _WIN32
//#				pragma message("XDA_DLL_API import in xstypesconfig.h")
#				define XDA_DLL_API __declspec(dllimport)
#			else
//#				pragma message("XDA_DLL_API import/static for linux in xstypesconfig.h")
#				define XDA_DLL_API
#			endif
#		endif
#	endif	// ifdef XDA_DLL_EXPORT - else
#endif	// ifndef XDA_DLL_API


#if !defined(XSENS_RELEASE)
//////////////////////////////////////////////////
// stuff for debug mode

#else
// non-debug stuff
//
#endif

//////////////////////////////////////////////////
// more generic preprocessor defines
//! Add this macro to the start of a class definition to prevent automatic creation of copy functions
#define XSENS_DISABLE_COPY(className) \
private: \
	className(const className &); \
	className &operator = (const className &);

// Some macros used by interface generator
#ifndef XSNOEXPORT
#define XSNOEXPORT
#endif
#ifndef XSNOLINUXEXPORT
#define XSNOLINUXEXPORT
#endif
#ifndef XSNOWINDOWSEXPORT
#define XSNOWINDOWSEXPORT
#endif
#ifndef XSNOMACEXPORT
#define XSNOMACEXPORT
#endif
#ifndef XSNOCOMEXPORT
#define XSNOCOMEXPORT
#endif

#endif	// file guard
