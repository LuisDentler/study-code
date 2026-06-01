#ifndef SMART_GREENHAOUSE_HPP
#define SMART_GREENHAOUSE_HPP   
#include <iostream>
#include <stdexcept>


class SensorFailureError : public std::runtime_error{
    
    public:
    SensorFailureError() : std::runtime_error("Sensor is unreachable"){};
};


class Sensor{
    private:
        std::string name;
        double value;
        constexpr static double MIN_POSSIBLE_VALUE = 0.0;
        constexpr static double MAX_POSSIBLE_VALUE = 100.0;

    public:
        Sensor(const std::string& sensor_name, double init_value):name(sensor_name), value(init_value){
            if(init_value <MIN_POSSIBLE_VALUE || init_value > MAX_POSSIBLE_VALUE){
                throw std::invalid_argument("Initial value for " +name+ "must be between " + std::to_string(MIN_POSSIBLE_VALUE) + " and " + std::to_string(MAX_POSSIBLE_VALUE));
            }
        };

        void update_value(double new_value){
            if(new_value < MIN_POSSIBLE_VALUE || new_value > MAX_POSSIBLE_VALUE){
                throw std::out_of_range("Value for " +name+ "must be between " + std::to_string(MIN_POSSIBLE_VALUE) + " and " + std::to_string(MAX_POSSIBLE_VALUE));
            }
            value = new_value;
        }
        double get_value() const{
            return value;
        }
        void print_info() const{
            std::cout << "Sensor: " << name << ", Value: " << value << std::endl;
        }
        void simulate_failure(){
            throw SensorFailureError();
        }
};




#endif // SMART_GREENHAOUSE_HPP
