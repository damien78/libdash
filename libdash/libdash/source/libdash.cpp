/*
 * libdash.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "../include/libdash.h"
#include "manager/DASHManager.h"

using namespace dash;

__declspec(dllexport) IDASHManager* __cdecl CreateDashManager()
{
    return new DASHManager();
}
__declspec(dllexport) mpd::IMPD* __cdecl CreateMpdFromMemory(const char *buffer, int size, const char *baseUri)
{
    if(buffer == NULL || size <= 0 || baseUri == NULL)
        return NULL;

    xml::DOMParser parser(buffer, size, baseUri);

    uint32_t fetchTime = helpers::Time::GetCurrentUTCTimeInSec();

    if (!parser.Parse())
        return NULL;

    mpd::MPD* mpd = parser.GetRootNode()->ToMPD();

    if (mpd)
        mpd->SetFetchTime(fetchTime);

    return mpd;
}