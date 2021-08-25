#include "lemon/engine.h"
#include <iostream>

int main()
{
    lemon::Engine& engine = lemon::Engine::Instance();
    engine.Run();

    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    return 0;
} 