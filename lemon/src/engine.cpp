#include "engine.h"
#include "sdl2/SDL.h"

#include <iostream>

namespace lemon
{
    void GetInfo() 
    {
#ifdef LEMON_CONFIG_DEBUG
        std::cout << "Configuration: Debug" << std::endl;
#endif
#ifdef LEMON_CONFIG_RELEASE
        std::cout << "Configuration: Release" << std::endl;
#endif
#ifdef LEMON_PLATFORM_WINDOWS
        std::cout << "Platform: Windows" << std::endl;
#endif
#ifdef LEMON_PLATFORM_LINUX
        std::cout << "Platform: Linux" << std::endl;
#endif
#ifdef LEMON_PLATFORM_MAC
        std::cout << "Platform: Mac" << std::endl;
#endif
    }

    bool Initialize() 
    {
        bool ret = true;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
            ret = false;
        }
        else
        {
            SDL_version version;
            SDL_VERSION(&version);
            std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;
        }

        return ret;
    }

    void Shutdown()
    {
        SDL_Quit();
    }

}