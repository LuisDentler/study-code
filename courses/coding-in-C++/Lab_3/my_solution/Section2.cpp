#include <iostream>
#include <string>


class User{
    protected:
        std::string name;
        int id;
    public:
        User(std::string name, int id){
            this->name = name;
            this->id = id;
        }
        void printInfo(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
        }
};

class Student : public User{
    private:
        std::string major;
    public:
        Student(std::string name, int id, std::string major) : User(name, id){
            this->major = major;
        }
        void printStudentInfo(){
            printInfo();
            std::cout << "Major: " << major << std::endl;
        }
};

class Instructor : public User{
    private:
        std::string department;
    public:
        Instructor(std::string name, int id, std::string department) : User(name, id){
            this->department = department;
        }
        void printInstructorInfo(){
            printInfo();
            std::cout << "Department: " << department << std::endl;
        }
};



int main(){

    Student student("Alice", 12345, "Computer Science");
    Instructor instructor("Dr. Smith", 67890, "Computer Science");
    std::cout << "Student Information:" << std::endl;
    student.printStudentInfo();
    std::cout << std::endl;
    std::cout << "Instructor Information:" << std::endl;
    instructor.printInstructorInfo();
    std::cout << std::endl;
    return 0;
}