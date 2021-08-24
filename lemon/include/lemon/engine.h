#pragma once

#include "core/window.h"

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
        bool mIsRunning;
        core::Window mWindow;

        // Private functions
        void GetInfo();
        void Shutdown();
        [[nodiscard]] bool Initialize();

        // Singleton
        Engine();
        static Engine* mInstance;
    };
}