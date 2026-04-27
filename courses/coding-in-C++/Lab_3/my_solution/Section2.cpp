#include <iostream>
#include <string>


class User{
    //Protected members can be accessed by derived classes
    protected:
        std::string name;
        int id;
    public:
        /**
         * @brief Constructs a User object.
         *
         * Initializes the user's name and id.
         *
         * @param[in] name  User's name
         * @param[in] id    User's ID
         */
        User(std::string name, int id){
            this->name = name;
            this->id = id;
        }
        /**
         * @brief Prints user information.
         *
         * Displays the user's name and ID.
         */
        void printInfo(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
        }
};

class Student : public User{
    private:
        std::string major;
    public:
        /**
         * @brief Constructs a Student object.
         *
         * Initializes the inherited User attributes and the student's major.
         *
         * @param[in] name  Student's name
         * @param[in] id    Student's ID
         * @param[in] major Student's major field of study
         */
        Student(std::string name, int id, std::string major) : User(name, id){
            this->major = major;
        }
        /**
         * @brief Prints student information.
         *
         * Displays the student's name, ID, and major.
         */
        void printStudentInfo(){
            printInfo();
            std::cout << "Major: " << major << std::endl;
        }
};

class Instructor : public User{
    private:
        std::string department;
    public:
        /**
         * @brief Constructs an Instructor object.
         *
         * Initializes the inherited User attributes and the instructor's department.
         *
         * @param[in] name        Instructor's name
         * @param[in] id          Instructor's ID
         * @param[in] department  Instructor's department
         */
        Instructor(std::string name, int id, std::string department) : User(name, id){
            this->department = department;
        }
        /**
         * @brief Prints instructor information.
         *
         * Displays the instructor's name, ID, and department.
         */
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