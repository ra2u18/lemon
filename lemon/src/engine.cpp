#include "engine.h"
#include "sdl2/SDL.h"

#include "log.h"

namespace lemon
{
    Engine& Engine::Instance()
    {
        if (!mInstance)
            mInstance = new Engine();
        
        return *mInstance;
    }

    // singleton
    Engine* Engine::mInstance = nullptr;
    Engine::Engine() : mIsRunning{ false }, mIsInitialized{ false } {}

    void Engine::Run()
    {
        if (Initialize()) {
            while (mIsRunning) {
                mWindow.PumpEvents();
                
                mWindow.BeginRender();
                 // render scene
                mWindow.EndRender();
            }
            Shutdown();
        }
    }

    void Engine::GetInfo() 
    {
#ifdef LEMON_CONFIG_DEBUG
        LEMON_DEBUG("Configuration: Debug");
#endif
#ifdef LEMON_CONFIG_RELEASE
        LEMON_DEBUG("Configuration: Release");
#endif
#ifdef LEMON_PLATFORM_WINDOWS
        LEMON_WARN("Platform: Windows");
#endif
#ifdef LEMON_PLATFORM_LINUX
        LEMON_WARN("Platform: Linux");
#endif
#ifdef LEMON_PLATFORM_MAC
        LEMON_WARN("Platform: Mac");
#endif
    }

    bool Engine::Initialize() 
    {
        bool ret = false;
        LEMON_ASSERT(!mIsInitialized, "Attempting to call Engine::Initialize() mode than once!");

        mLogManager.Initialize();
        GetInfo();

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            LEMON_ERROR("Error initializing SDL2: {}", SDL_GetError());
        }
        else
        {
            SDL_version version;
            SDL_VERSION(&version);
            LEMON_INFO("SDL {}.{}.{}", (int32_t)version.major, (int32_t)version.minor, (int32_t)version.patch);
        
            if (mWindow.Create()) {
                ret = true;
                mIsInitialized = true;
                mIsRunning = true;
            }
        }

        if (!ret) {
            LEMON_ERROR("Engine initialization failed, shutting down...");
            Shutdown();
        }

        return ret;
    }

    void Engine::Shutdown()
    {
        mIsRunning = false;
        mIsInitialized = false;

        // Managers - usually in reverse order
        mLogManager.Shutdown();

        // Shutdown SDL
        mWindow.Shutdown();
        SDL_Quit();
    }

}