#include <iostream>
#include "firstHeader.hpp"




void printFromHeader()
{
    std::cout << "Hello from .hpp" << std::endl;
}


int main()
{
    std::cout << "Hello World" << std::endl;
    printFromHeader();
    return 0;
}

