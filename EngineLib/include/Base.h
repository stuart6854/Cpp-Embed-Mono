//
// Created by stumi on 11/11/21.
//

#ifndef _EMBED_MONO_BASE_H
#define _EMBED_MONO_BASE_H

#if defined(_WIN32) && defined(_ENGINE_BUILD_DLL)
// We are building as a Win32 DLL
#define ENGINE_API __declspec(dllexport)
#elif defined(_WIN32) && defined(ENGINE_DLL)
// We are calling as a Win32 DLL
#define ENGINE_API __declspec(dllimport)
#else
// We are building or calling as a static library
#define ENGINE_API
#endif

#endif//_EMBED_MONO_BASE_H
