#include "lemon/engine.h"

#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    
    lemon::Initialize();
    lemon::Shutdown();

#ifdef LEMON_PLATFORM_WINDOWS
    system("pause");
#endif

    return 0;
} 