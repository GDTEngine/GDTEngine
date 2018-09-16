/**
 * @file     Log.hpp
 * @author   Ludvig Arlebrink
 * @date     9/17/2018
 */

#pragma once

#if GDT_DEBUG

    #include <iostream>
    #define LOG(msg) std::cout << msg
    #define LOG_MSG(msg) std::cout << "MSG :: " << msg << "\n"
    #define LOG_ERROR(msg) std::cout << "ERROR :: " << msg << "\n"
    #define LOG_SEPERATOR std::cout << "\n****************************************\n\n";
    #define LOG_WARNING(msg) std::cout << "WARNING :: " << msg << "\n"

#else

    #define LOG(msg)
    #define LOG_MSG(msg)
    #define LOG_ERROR(msg)
    #define LOG_SEPERATOR
    #define LOG_WARNING(msg)

#endif
