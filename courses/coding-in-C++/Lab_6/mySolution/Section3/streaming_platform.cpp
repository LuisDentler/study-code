#include "streaming_plattform.hpp"
#include <iostream>



int main(){
    Room room1 ("Kitchen");
    room1.add_device(std::make_unique<Device>("TV", "Entertainment"));
    room1.add_device(std::make_unique<Device>("Fridge", "Appliance"));
    room1.print_devices();
    auto p1 = std::make_unique<int>(42);
    auto p2 = std::move(p1);
    std::cout << std::boolalpha << (p1 == nullptr) << std::endl;

    return 0;
}

