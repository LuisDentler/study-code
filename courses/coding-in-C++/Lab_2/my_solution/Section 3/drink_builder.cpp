#include <iostream>
#include <string>

constexpr int MAX_SUGAR_AMOUNT = 10;

class DrinkBuilder
{
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;

    public:
        DrinkBuilder& setName(const std::string& drinkname){
            this->name = drinkname;
            return *this;
        }
        DrinkBuilder& setSugar(int sugar_amount){
            this->sugar = sugar_amount;
            return *this;
        }
        DrinkBuilder& setTemp(int drinktemp){
            this->temperature = drinktemp;
            return *this;
        }
        DrinkBuilder& setMilk(bool add_milk){
            this->withMilk = add_milk;
            return *this;
        }

        void printDrink(){
            std::cout <<"Name: " <<name<<std::endl;
            std::cout <<"Sugar: " <<sugar<<std::endl;
            std::cout <<"Temperature: " <<temperature<<std::endl;
            std::cout <<"With Milk?: " <<std::boolalpha<<withMilk<<std::endl;
    }
        const void isValid(){
            if (sugar > MAX_SUGAR_AMOUNT)
            {
                this->sugar = 0;
                std::cout<<"Sugar must be 10 or lower!"<<std::endl;
            }else 
            {
                std::cout<<"Your drink is valid. Enjoy!"<<std::endl;
            }
            
            
        }
};


int main()
{
    DrinkBuilder firstDrink;
    firstDrink.setName("Eistee")
    .setMilk(false)
    .setSugar(13)
    .setTemp(10);
    firstDrink.isValid();
    firstDrink.printDrink();
    return 0;
}