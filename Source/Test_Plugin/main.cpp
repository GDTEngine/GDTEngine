#pragma once

// includes we need
#include "Entity.hpp"

#include <string>
#include <memory>
#include <iostream>
#include <Windows.h>
#include "ClassManager.hpp"

// Test to see if we are building a DLL.
// If we are, specify that we are exporting
// to the DLL, otherwise don't worry (we
// will manually import the functions).
#ifdef DLL_EXPORT
#define GDC_API __declspec(dllexport)
#else
#define GDC_API __declspec(dllimport)
#endif // DLL_EXPORT

class CPlayer : public CEntity
{
public:
    CPlayer()
    {
        
    }

    ~CPlayer()
    {
        
    }

    void tick(f32 deltaTime) override
    {
        std::cout << "HELLO I AM A PLAYER\n";
    }
};

// Get an instance of the derived class
// contained in the DLL.
extern "C" GDC_API void begin()
{
    std::cout << "DLL Loaded\n";
    
    CClassManager::get().registerEntity("CPlayer", []()->CEntity* { return new CPlayer; });
}

// Get the name of the plugin. This can
// be used in various associated messages.
extern "C" GDC_API void end()
{
    
}

// GDC_API BOOL APIENTRY DllMain(HINSTANCE hInst,
//     DWORD reason,
//     LPVOID reserved)
// {
//     switch (reason)
//     {
//         case DLL_PROCESS_ATTACH:
//             begin();
//             break;
// 
//         case DLL_PROCESS_DETACH:
//             // detaching from process
//             break;
// 
//         case DLL_THREAD_ATTACH:
//             // attach to thread within process
//             break;
// 
//         case DLL_THREAD_DETACH:
//             // detach from thread within process
//             break;
//     }
// 
//     // return success
//     return TRUE;
// }
