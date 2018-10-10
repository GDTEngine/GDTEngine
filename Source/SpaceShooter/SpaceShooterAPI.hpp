/**
* @file     SpaceShooterAPI.hpp
* @author   Ludvig Arlebrink
* @date     9/30/2018
*/

#pragma once

#ifdef SPACESHOOTER_DLL_EXPORT
#define SPACESHOOTER_API __declspec(dllexport)
#else
#define SPACESHOOTER_API __declspec(dllimport)
#endif // SPACESHOOTER_DLL_EXPORT
