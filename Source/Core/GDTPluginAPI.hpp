/**
 * @file     GDTPluginAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     9/27/2018
 */

#pragma once

#ifdef GDT_PLUGIN_DLL_EXPORT
#define GDT_PLUGIN_API extern "C" __declspec(dllexport)
#else
#define GDT_PLUGIN_API
#endif // GDC_PLUGIN_DLL_EXPORT
