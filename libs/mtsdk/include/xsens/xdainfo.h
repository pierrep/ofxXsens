#ifndef XDAINFO_H
#define XDAINFO_H

struct XsVersion;
struct XsString;

#ifdef __cplusplus
extern "C" {
#endif

XDA_DLL_API void xdaDllVersion(struct XsVersion* version);
XDA_DLL_API void xdaDllPath(struct XsString* path);
XDA_DLL_API void xdaSetLogPath(const struct XsString* path);

#ifdef __cplusplus
}
#endif

#endif	// file guard
