//Wichtige Bibliotheken 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

//include "beispiele.h"
#include "beispiele.hpp"

//Namespaces 
namespace std{};
// using namespace std; -> nicht empfohlen, da es zu Namenskonflikten führen kann

//Klassen:
class Beispiel{
    //Private, Protected und Public Zugriffsmodifikatoren
    private:
        int beispielVariable;
    protected:
        int geschuetzteVariable;
    public:
        //---Konstruktoren---
        //Default Konstruktor
        Beispiel(){
            beispielVariable = 0;
            geschuetzteVariable = 0;
        }
        //Parametrisierter Konstruktor
        Beispiel(int var){
            beispielVariable = var;
            geschuetzteVariable = var;
        }
        //Konstruktor mit Initialisierungsliste
        Beispiel(int var1, int var2) : beispielVariable(var1), geschuetzteVariable(var2) {}
        //Kopierkonstruktor
        Beispiel(const Beispiel &other){
            beispielVariable = other.beispielVariable;
            geschuetzteVariable = other.geschuetzteVariable;
        }
        //virtueller Konstruktor (ab C++20)
        


        //---Methoden---
        void beispielMethode(){
            std::cout << "Dies ist eine Beispielmethode!" << std::endl;
        }
        void beispielMethodeMitParameter(int param){
            std::cout << "Der übergebene Parameter ist: " << param << std::endl;
        }
        int beispielMethodeMitRückgabewert(){
            return beispielVariable;
        }


        //---Destruktoren---
        //Standard Destruktor
        ~Beispiel(){
            //Ressourcen freigeben, falls notwendig
        }
        //Virtueller Destruktor
        virtual ~Beispiel(){
            //Ressourcen freigeben, falls notwendig
        }

};


int main(){



    //immer return 0 am Ende der main Funktion, um anzuzeigen, dass das Programm erfolgreich ausgeführt wurde
    return 0;
}