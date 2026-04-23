#include <iostream>
#include <string>


class Note
{

    private: 
        std::string* text;
    
    public:
        Note(std::string input)
        {
            text = new std::string;
            *text = input;
        }

        Note(const Note &otherNote)
        {
            text = new std::string;
            *text = *otherNote.text;
        }

        ~Note()
        {
            delete text;
            text = nullptr;
            std::cout << "peicher freigegeben" << std::endl;
        }

        void display()
        {
            std::cout <<*text<< std::endl;
        }
};

int main()
{
    Note note1("Bla bla bla");
    Note note2 = note1;

    note1.display();
    note2.display();

    return 0;
} 

