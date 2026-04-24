#include <iostream>
#include <string>
#include <limits>
#include <cstdint>

void readStudentData(std::string &name,uint_fast16_t &homework,uint_fast16_t &midterm,uint_fast16_t &finalExam)
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
    while (true)
    {
        std::cout <<"Enter your Midtermscore: " <<std::endl;

        std::cin >> std::ws;

        if (!(std::cin >> midterm))
        {
            std::cout <<"No number entered" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (midterm > MAX_LENGTH_SCORE)
        {
            std::cout <<"Score is to big (>100)!" <<std::endl;
            continue;
        }
        break;
    }
    while (true)
    {
        std::cout <<"Enter your Finalscore: " <<std::endl;

        std::cin >> std::ws;

        if (!(std::cin >> finalExam))
        {
            std::cout <<"No number entered" <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (finalExam > MAX_LENGTH_SCORE)
        {
            std::cout <<"Score is to big (>100)!" <<std::endl;
            continue;
        }
        break;
    }
    
} 

float calculateGrade(uint_fast16_t homework,uint_fast16_t midterm,uint_fast16_t finalExam)
{
    const float HOMEWORK_WEIGHT = 0.4f;
    const float MIDTERM_WEIGHT = 0.3f;
    const float FINALEXAM_WEIGHT = 0.3f;
    
    float grade = static_cast<float>(homework) * HOMEWORK_WEIGHT + static_cast<float>(midterm) * MIDTERM_WEIGHT + static_cast<float>(finalExam) * FINALEXAM_WEIGHT;

    return grade;
}

std::string calculateLetterGrade(float grade)
{
    std::string letter_grade;
    const float A_THRESHOLD = 90.0f;
    const float B_THRESHOLD = 80.0f;
    const float C_THRESHOLD = 70.0f;
    const float D_THRESHOLD = 60.0f;

    if (grade >= A_THRESHOLD)
    {
        letter_grade = "A";
    }
    else if (grade >= B_THRESHOLD)
    {
        letter_grade = "B";
    }
    else if (grade >= C_THRESHOLD)
    {
        letter_grade = "C";
    }
    else if (grade >= D_THRESHOLD)
    {
        letter_grade = "D";
    }
    else
    {
        letter_grade = "F";
    }

    return letter_grade;
}

int main()
{

    std::string name;
    uint_fast16_t homework;
    uint_fast16_t midterm;
    uint_fast16_t finalExam;

    readStudentData(name, homework, midterm, finalExam);
    float grade = calculateGrade(homework, midterm, finalExam);
    std::string letter_grade = calculateLetterGrade(grade);
    std::cout << "Student Name: " << name << std::endl;
    std::cout << "Final Grade: " << grade << std::endl;
    std::cout << "Letter Grade: " << letter_grade << std::endl;

    return 0;
}
