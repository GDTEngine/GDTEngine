/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include <cstring>
#include <vector>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>

std::vector<HINSTANCE> g_modules;
typedef int(__cdecl *PLUGINPROC)();

#endif


int main(int argc, char* argv[])
{
#ifdef GDT_EDITOR
    auto launchEditor = false;

    if (argc > 1)
    {
        if (!strcmp("-e", argv[1]))
        {
            launchEditor = true;
        }
    }
#endif

#ifdef _WIN32
    WIN32_FIND_DATA fileData;
    HINSTANCE tmp = LoadLibrary(TEXT("./Plugins/SpaceShooter.dll"));
    if (!tmp)
    {
        std::cout << "COULD NOT LOAD LIB\n";
    }

    PLUGINPROC begin = (PLUGINPROC)GetProcAddress(tmp, "startUpPlugin");
    if (!begin)
    {
        std::cout << "No proc address added\n";
    }
    else
    {
        (begin)();
    }

#endif // _WIN32

    getchar();
}
