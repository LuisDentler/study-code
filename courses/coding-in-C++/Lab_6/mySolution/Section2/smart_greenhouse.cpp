#include "smart_greenhaouse.hpp"
#include <stdexcept>
#include <iostream>


int main(){

    try {
        Sensor temp_sensor("Temperature", 25.0);
        Sensor humidity_sensor("Humidity", 60.0);

        temp_sensor.print_info();
        humidity_sensor.print_info();

        temp_sensor.update_value(30.0);
        humidity_sensor.update_value(55.0);

        temp_sensor.print_info();
        humidity_sensor.print_info();

        // This will throw an exception
        temp_sensor.update_value(150.0);
    }
    catch(const std::out_of_range& e){
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cerr << "Invalid Argument error: " <<e.what() <<std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }



    return 0;
}