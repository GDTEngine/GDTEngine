/**
 * @file     main.cpp
 * @author   Ludvig Arlebrink
 * @date     9/22/2018
 */

#include <cstring>

int main(int argc, char* argv[])
{
#ifdef GDT_EDITOR

    bool launchEditor = false;

    if (argc > 1)
    {
        if (!strcmp("-e", argv[1]))
        {
            launchEditor = true;
        }
    }

#endif

}
