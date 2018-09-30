/**
 * @file     EngineAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#ifdef ENGINE_DLL_EXPORT
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_DLL_EXPORT
