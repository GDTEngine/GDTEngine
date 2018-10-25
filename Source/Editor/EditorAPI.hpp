/**
 * @file     EngineAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#ifdef EDITOR_DLL_EXPORT
#define EDITOR_API __declspec(dllexport)
#else
#define EDITOR_API __declspec(dllimport)
#endif // EDITOR_DLL_EXPORT
