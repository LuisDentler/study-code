#include <iostream>
#include <string>
#include <limits>

void readStudentData(std::string &name,int &homework,int &midterm,int &finalExam)
{
    const int MAX_LENGTH_SCORE = 100;

    std::cout <<"Enter Student Name: " << std::endl;

    std::cin >> std::ws;

    if (!(std::getline(std::cin, name)))
    {
        std::cout <<"Fehler bei der Eingabe" <<std::endl;
    }

    while (true)
    {
        std::cout <<"Enter your Homeworkscore: " <<std::endl;

        std::cin >> std::ws;

        if (!(std::cin >> homework))
        {
            std::cout <<"No number entered" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (homework > MAX_LENGTH_SCORE)
        {
            std::cout <<"Score is to big (>100)!" <<std::endl;
            continue;
        }
        break;
        
    }
} 


int main()
{
    readStudentData; 

    return 0;
}
