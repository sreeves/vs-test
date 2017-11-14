#include <iostream>
#include <stdexcept>
#include "jsapi.h"
#include "js/Initialization.h"

int main(int argc, char** args){

    std::cout<< "Start...\n";

    if(!JS_Init())
        throw std::runtime_error("Failed to initialize");

    std::cout << "It's alive!\n";

    JS_ShutDown();

    std::cout << "Finished\n";
    return 0;
}
