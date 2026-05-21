#include "drone_test_bench.hpp"

#include <iostream>
#include <string>


int main(){
   
    int value1 = 10;
    int value2 = 20;
    std::cout << "Before swap: value1 = " << value1 << ", value2 = " << value2 << std::endl;
    swapValue(value1, value2);
    std::cout << "After swap: value1 = " <<value1 <<" Value2: " << value2 << std::endl;
    char sensorFrames[5] = {'?', '?', '?', '?', '?'};
    printSensorFrames(sensorFrames);
    printSensorMetadata("Battery Level", 85, "Status", "OK");
    return 0;
}