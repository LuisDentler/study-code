#include <iostream>
#include <string>

class BankAccount 
{
    private:
        std::string owner;
        double kontostand = 1000;

    public:
        void setOwner(std::string name)
        {
            owner = name;
        }

        std::string getOwner()
        {
            return owner;
        }

        void einzahlen(int ein_value)
        {
            if (ein_value > 0)
            {
                kontostand = kontostand + ein_value;
            }
            else{
                std::cout <<"Betrag zu klein"<<std::endl;
            }
            
            
        }

        void auszahlen(int aus_value)
        {
            if (aus_value > kontostand)
            {
                std::cout << "Zu wenig Geld auf Konto"<< std::endl;
            }
            
            kontostand = kontostand - aus_value;
        }

        void getKontostand();
};

void BankAccount :: getKontostand()
{
    std::cout <<kontostand<< std::endl;
}

int main()
{
    BankAccount acc_one;

    std::string name = "Hans";
    int stand = 100; 
    acc_one.setOwner(name);
    acc_one.einzahlen(0);
    acc_one.getKontostand();
    acc_one.auszahlen(200);
    acc_one.getKontostand();
    acc_one.auszahlen(10000);
}