/**
 *  libdash.h
 *
 *  @brief      The main interface to the libary that should be used to create a IDASHManager
 *  @details    ...
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef LIBDASH_H_
#define LIBDASH_H_

#include "config.h"

#if defined _WIN32 || defined _WIN64
#else
#define __declspec(dllexport)
#define __cdecl
#endif

#include "IDASHManager.h"

__declspec(dllexport) dash::IDASHManager* __cdecl CreateDashManager();

/**
 *  Parses an MPD that is already in memory and returns the resulting dash::mpd::IMPD, or NULL.
 *  @param  buffer   the MPD document. Not owned, and only has to stay valid for this call.
 *  @param  size     length of \em buffer in bytes.
 *  @param  baseUri  the absolute URI the MPD was retrieved from. Its directory becomes the MPD path
 *                   base URL, i.e. what relative <BaseURL> elements and segment URIs resolve
 *                   against -- so pass the URL AFTER redirects, with any query string stripped.
 */
__declspec(dllexport) dash::mpd::IMPD* __cdecl CreateMpdFromMemory(const char *buffer, int size, const char *baseUri);

#endif /* LIBDASH_H_ */
