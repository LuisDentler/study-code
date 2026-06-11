#include "vorbereitung.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>


double divideValues(double a, double b){
    if(b == 0){
        throw std::invalid_argument("Division by 0 \n");
    }
    return static_cast<double>(a/b);
}


int main(){
    /*
    Klasse k1(0,0,"");
    k1.setAnzLehr(5)
    .setAnzSus(25)
    .setName("12a");
    k1.printKlasse();

    int testzahl = 0;
    while(true){
        std::cout<<"Gib eine Zahl ein: ";
        std::cin>> testzahl;
        if(std::cin.fail()){    
            std::cout<<"Invalid input"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        std::cout<<testzahl<<std::endl;
        break;
    }
    */

    double a = 5;
    double b = 0;
    try{
    divideValues(a,b);
    }
    catch(const std::invalid_argument& e){
        std::cout<<e.what();
    }
    catch(const std::exception& e){
        std::cout<<"default catch Block "<<e.what();
    }
    return 0;
}
