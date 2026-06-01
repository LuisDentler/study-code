#ifndef STREAMING_PLATTFORM_HPP
#define STREAMING_PLATTFORM_HPP
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <memory>

class Device{
    private:
        std::string device_name;
        std::string device_type;
        bool power_satus = false;
    public:
        Device(std::string name, std::string type): device_name(name), device_type(type){}


        std::string get_name() const{
            return device_name;
        }

        void turn_on(){
            power_satus = true;
            std::cout << device_name << " is now ON." << std::endl;
        }
        void turn_off(){
            power_satus = false;
            std::cout << device_name << " is now OFF." << std::endl;
        }
        void print_info()const{
            std::cout << "Device Name: " << device_name << std::endl;
            std::cout << "Device Type: " << device_type << std::endl;
            std::cout << "Power Status: " << (power_satus ? "ON" : "OFF") << std::endl;
        }
        ~Device(){
            std::cout << "Device " << device_name << "is destroyed." << std::endl;
        }


};

class Room{
    private: 
        std::string room_name;
        std::list<std::unique_ptr<Device>> devices;

    public:
        Room(std::string name): room_name(name){};

        void add_device(std::unique_ptr<Device> device){
            devices.push_back(std::move(device));
        }

        void remove_device_by_name(const std::string& name){
            devices.remove_if([&name](const std::unique_ptr<Device>& device){
                return device->get_name() == name;
            });
        }

        void print_devices() const{
            std::cout << "Devices in " << room_name << ":" << std::endl;
            for(const auto& device : devices){
                device->print_info();
                std::cout << "-------------------" << std::endl;
            }
        }
};



#endif