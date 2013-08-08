#ifndef __XSENS_LINUX_H
#define __XSENS_LINUX_H

#ifdef __GNUC__

#include "pstdint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wchar.h>
#include <assert.h>
#include <pthread.h>

#define LPSTR char *
#define _T

#define _ASSERT assert
#define _ASSERTE assert
#define HMODULE void *

#define LINUX_MBS_LENGTH 256
#define LINUX_MBS_MODELENGTH 5

#ifdef __cplusplus
#define XSEXTC extern "C"
#else
#define XSEXTC
#endif

#ifndef HAVE_SPRINTF_S
XSEXTC int32_t sprintf_s(char *dest, uint32_t num, const char *fmt, ...);
#endif

#ifndef HAVE_STRCPY_S
XSEXTC int32_t strcpy_s(char *dest, uint32_t size, const char *src);

#ifdef __cplusplus
template <uint32_t size>
int32_t strcpy_s(char (&dest)[size], const char *src)
{
	if (!src) return EINVAL;
	if (size == 0 || size < strlen(src) + 1) return ERANGE;

	strcpy(dest, src);

	return 0;
}
#endif
#endif

#ifndef HAVE_STRCAT_S
XSEXTC int32_t strcat_s(char *dest, uint32_t size, const char *src);

#ifdef __cplusplus
template <uint32_t size>
int32_t strncpy_s(char (&dest)[size], const char *src, uint32_t count)
{
	if (!src) return EINVAL;
	uint32_t itemsToAdd = (count < strlen(src) ? count : strlen(src));
	if (size == 0 || size < itemsToAdd + 1) return ERANGE;

	strncpy(dest, src, count);

	return 0;
}
#endif
#endif

#ifndef HAVE_STRNCPY_S
XSEXTC int32_t strncpy_s(char *dest, uint32_t size, const char *src, uint32_t count);

#ifdef __cplusplus
template <uint32_t size>
int32_t strcat_s(char (&dest)[size], const char *src)
{
	if (!src) return EINVAL;
	if (size == 0 || size < strlen(src) + strlen(dest) + 1) return ERANGE;

	strcat (dest, src);

	return 0;
}
#endif
#endif

#ifndef HAVE_FOPEN_S
XSEXTC int fopen_s(FILE **file, const char *filename, const char *mode);
#endif

#define _stricmp strcasecmp
#define stricmp strcasecmp
#define _strnicmp strncasecmp
#define strnicmp strncasecmp

/* not available on cygwin */
#ifdef HAVE_WCSCASECMP
#define _wcsicmp wcscasecmp
#else
#define _wcsicmp(s1, s2)		compat_wcsnicmp(s1, s2, 0x7fffffff)
extern int compat_wcsnicmp(const wchar_t* s1, const wchar_t* s2, size_t length);
#endif

/* not available on cygwin */
#ifdef HAVE_WCSNCASECMP
#define _wcsnicmp wcsncasecmp
#else
#define _wcsnicmp(s1, s2, n)	compat_wcsnicmp(s1, s2, n)
extern int compat_wcsnicmp(const wchar_t* s1, const wchar_t* s2, size_t length);
#endif

#define _wfopen wfopen
#ifndef HAVE_WFOPEN
#define wfopen compat_wfopen
extern FILE *compat_wfopen(const wchar_t *filename, const wchar_t *mode);
#endif

#define _wfreopen wfreopen
#ifndef HAVE_WFREOPEN
#define wfreopen compat_wfreopen
extern FILE *compat_wfreopen(const wchar_t *path, const wchar_t *mode, FILE *);
#endif

#define _set_printf_count_output(x)

#define _strdup strdup
#define _wcsdup wcsdup

#define fullpath(src,dest,len) realpath(src,dest)
#define _fullpath fullpath

#define _wfullpath compat_wfullpath
extern int32_t compat_wfullpath(wchar_t *resolvedPath, const wchar_t *path, size_t length);

#ifndef _finite
#define _finite(x) finite(x)
#endif

#ifndef HAVE_STRTOK_S
extern char *strtok_s(char *token, const char *delim, char **context);
#endif

#define LOBYTE(w)	((uint8_t)((w) & 0xff))
#define HIBYTE(w)	((uint8_t)(((w) >> 8) & 0xff))

#define __assume(val)

#if !defined(HAVE_CDECL)
#	if !defined(__cdecl)
#		if defined(__x86_64__)
#			define __cdecl
#		else
#			define __cdecl __attribute__((cdecl))
#		endif
#	endif
#	if !defined(__stdcall)
#		if defined(__x86_64__)
#			define __stdcall
#		else
#			define __stdcall __attribute__((stdcall))
#		endif
#	endif
#endif

#define _unlink unlink
#define __debugbreak()
#define _fileno fileno
#define _strdup strdup
#define _isnan isnan

#define GetRValue(rgb) ((uint8_t)(rgb))
#define GetGValue(rgb) ((uint8_t)(((uint32_t)(rgb)) >> 8))
#define GetBValue(rgb) ((uint8_t)(((uint32_t)(rgb)) >> 16))

typedef pthread_mutex_t CRITICAL_SECTION;

#ifdef __cplusplus
inline void InitializeCriticalSection(CRITICAL_SECTION *cs)	{ pthread_mutex_init(cs, 0); }
inline void DeleteCriticalSection(CRITICAL_SECTION *cs)		{ pthread_mutex_destroy(cs); }
inline void EnterCriticalSection(CRITICAL_SECTION *cs)		{ pthread_mutex_lock(cs); }
inline bool TryEnterCriticalSection(CRITICAL_SECTION *cs)	{ return (pthread_mutex_trylock(cs) == 0); }
inline void LeaveCriticalSection(CRITICAL_SECTION *cs)		{ pthread_mutex_unlock(cs); }
#else
#define InitializeCriticalSection(cs)	pthread_mutex_init(cs, 0)
#define DeleteCriticalSection(cs)		pthread_mutex_destroy(cs)
#define EnterCriticalSection(cs)		pthread_mutex_lock(cs)
#define TryEnterCriticalSection(cs)		(pthread_mutex_trylock(cs) == 0)
#define LeaveCriticalSection(cs)		pthread_mutex_unlock(cs)
#endif

#ifndef DWORD
#	define DWORD uint32_t
#endif

XSEXTC int IsBadWritePtr(void *p, size_t size);

#undef XSEXTC

#define _TRUNCATE 1
#define vsnprintf_s(str, size, thingy, fmt, vp) vsnprintf(str, size, fmt, vp)


#endif // __GNUC__
#endif // __XSENS_LINUX_H
