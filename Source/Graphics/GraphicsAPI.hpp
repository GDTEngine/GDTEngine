/**
 * @file     GraphicsAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#ifdef GRAPHICS_DLL_EXPORT
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif // GRAPHICS_DLL_EXPORT
