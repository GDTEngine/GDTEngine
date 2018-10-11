/**
 * @file     CoreAPI.hpp
 * @author   Ludvig Arlebrink
 * @date     9/30/2018
 */

#pragma once

#ifdef CORE_DLL_EXPORT
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // CORE_DLL_EXPORT
