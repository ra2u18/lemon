#pragma once

#include "core/window.h"
#include "managers/logmanager.h"

namespace lemon
{
    class Engine
    {
    public:
        static Engine& Instance();
        ~Engine() {}

        void Run();
        inline void Quit() { mIsRunning = false; }

    private:
        void GetInfo();
        void Shutdown();
        [[nodiscard]] bool Initialize();
    private:
        bool mIsRunning;
        bool mIsInitialized;

        core::Window mWindow;

        // Managers
        managers::LogManager mLogManager;

        // Singleton
        Engine();
        static Engine* mInstance;
    };
}