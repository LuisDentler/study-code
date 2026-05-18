#include <stdexcept>
#include <string>
#include <iostream>

class ConfigLoader{

    public:
    ConfigLoader() = default;
    void load(const std::string& filename){
        if(filename.empty()){
            throw std::invalid_argument("Filename cannot be empty");
        }
        if(filename == "missing.cfg"){
            throw std::runtime_error("Configuration file cannot be opened");
        }
        if(filename == "invalid.cfg"){
            throw std::runtime_error("Configuration file is invalid");
        }
    }
    ~ConfigLoader() = default;

};


int main(){
    ConfigLoader loader;
    try{
        loader.load("");
    }catch(const std::invalid_argument& e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }catch(const std::exception& e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try{
        loader.load("missing.cfg");
    }catch(const std::runtime_error& e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }catch(const std::exception& e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try{
        loader.load("invalid.cfg");
    }catch(const std::runtime_error& e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }catch(const std::exception& e){
        std::cout << "Caught exception: " << e.what() << std::endl; 
    }
    
    return 0;
}