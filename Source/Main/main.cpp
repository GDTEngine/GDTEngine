/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include <cstring>
#include <vector>

#ifdef _WIN32
#include <Windows.h>

std::vector<HINSTANCE> g_modules;

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

#ifdef _WIN32
    WIN32_FIND_DATA fileData;
    HANDLE fileHandle = FindFirstFile(TEXT("./Plugins/*.dll"), &fileData);

    getchar();

#endif
#endif
}
