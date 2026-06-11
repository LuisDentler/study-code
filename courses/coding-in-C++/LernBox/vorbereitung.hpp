#ifndef VORBEREITUNG_HPP
#define VORBEREITUNG_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>


//Vererbung
class Mensch{
    private:
        std::string name;
        int age;
        bool alive;

    public: 

        Mensch(std::string name, int age, bool alive):name(name),age(age), alive(alive){};

        std::string getName()const{
            return name;
        }
        void setName(const std::string& pname){
            name = pname;
        }
        int getAge()const{
            return age;
        }
        void setAge(int page){
            age = page;
        }
        bool getAlive()const{
            return alive;
        }
        virtual void setGeschlecht(const std::string& geschlecht)=0;
        virtual ~Mensch()= default;
};

class Mann : public Mensch{
    private:
        std::string geschlecht;
    public:
        Mann(std::string name, int age, bool alive, std::string geschlecht):Mensch(name,age, alive), geschlecht(geschlecht){};
        void setGeschlecht(const std::string& pgeschlecht)override{
            geschlecht = pgeschlecht;
        }
        std::string getGeschlecht()const{
            return geschlecht;
        }

};

//Assotioation
class Buch{
    private:
        std::string titel;
        std::string autor;
    public:

        Buch(std::string titel, std::string autor):titel(titel),autor(autor){};

        std::string getTitel()const{
            return titel;
        }
        std::string getAutor()const{
            return titel;
        }
};

class Kunde{
    private: 
        std::string name;
        std::vector<Buch*> ausleihen;

    public:
        Kunde(std::string name):name(name){};
        void buchAusleihen(Buch* b){
            ausleihen.push_back(b);
        }
        void zeigeAusleihe()const{
            for(Buch* b : ausleihen){
                std::cout<<"Buch: "<< b->getAutor() <<b->getTitel() <<std::endl;
            }
        }
};


//Aggregation
class Spieler{
    private:
        std::string name;
        int rueckennummer;

    public:
        Spieler(std::string name, int rueckennummer):name(name),rueckennummer(rueckennummer){};
        std::string getName()const{
            return name;
        }
        int getRueckenname()const{
            return rueckennummer;
        }
};

class Mannschaft{
    private:
    std::string name;
    std::vector<Spieler*> spieler;

    public:
        Mannschaft(std::string name): name(name){};
        void addSpieler(Spieler* s){
            spieler.push_back(s);
        }
        void zeigeMannschaft()const{
            std::cout<<name<<": " ;
            for(Spieler* s : spieler){
                std::cout<< s->getName()<<" ";
            }
            std::cout<<std::endl;
        }

};


//Komposition
class Zimmer{
    private: 
        std::string name;
        int qmeter;
    
    public:
        Zimmer(std::string name, int qmeter): name(name), qmeter(qmeter){};
        std::string getName()const{
            return name;
        }
        int getQmeter()const{
            return qmeter;
        }

};

class Haus{
    private:
        std::string adresse;
        std::vector<std::unique_ptr<Zimmer>> zimmer;

    public:
        Haus(std::string adresse):adresse(adresse){};
        void addZimmer(std::string name, int qmeter){
            zimmer.push_back(std::make_unique<Zimmer>(name,qmeter));
        }
        void zeigeZimmer()const{
            std::cout<<"Haus: "<<adresse<<" ";
            for(const std::unique_ptr<Zimmer>& z : zimmer){
                std::cout<<z->getName()<<" ";
            }
            std::cout<<std::endl;
        }

};


//Methodchaining 
class Klasse{
    private: 
        int AnzSus;
        int AnzLehr;
        std::string name;

    public: 
        Klasse(int AnzSus, int AnzLehr, std::string name): AnzSus(AnzSus), AnzLehr(AnzLehr), name(name){};

        Klasse& setAnzSus(int anzahl){
            this->AnzSus = anzahl;
            return *this;
        }
        Klasse& setAnzLehr(int anzahl){
            this->AnzLehr = anzahl;
            return *this;
        }
        Klasse& setName(std::string name){
            this->name = name;
            return *this;
        }
        void printKlasse()const{
            std::cout<<"Klasse: "<<name<<std::endl<<"Anz Sus: "<<AnzSus<<std::endl<<"Anz Lehr: "<<AnzLehr<<std::endl;
        }

};



#endif
