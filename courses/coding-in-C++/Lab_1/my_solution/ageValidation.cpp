#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

namespace validation
{
    const std::uint8_t MIN_LIMIT_ADULT = 18;
    const std::uint8_t MIN_LIMIT_SENIOR = 65;

    bool isAdult(std::uint8_t age)
    {
        return age>=MIN_LIMIT_ADULT;
    }

    bool isSenior(std::uint8_t age)
    {
        return age>=MIN_LIMIT_SENIOR;
    }

}

int main()
{
    const std::uint8_t MAX_VALID_AGE = 130;
    int age;
    std::cout <<"Please enter your age: ";

    while (true)
    {
        if (!(std::cin >> age))
        {
            std::cout <<"No Valid Input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (age<=0)
        {
            std::cout <<"No Valid Input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (age > MAX_VALID_AGE)
        {
            std::cout <<"No Valid Input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
        std::cout <<"Please enter your age: ";
    }
    
    std::cout <<"Your are " <<age << " old." << std::endl;

    if (validation::isSenior(age))
    {
       std::cout <<"That means you are an Senior."; 
    }
    else if (validation::isAdult(age))
    {
        std::cout <<"That means you are an Adult.";
    }
    else
    {
        std::cout <<"That means you are an Kid.";
    }
    
    return 0;

}
