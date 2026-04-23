//Problem: Kein File Header 
#include <iostream>
#include <string>
//Problem: "iomanip" wird eig nie verwendet --unbekannt für mich 
#include <iomanip>

//Using sollte nicht verwendet werden 
using namespace std;

class Article {
public:
    //Problem: Attribut befindet sich in Public wodurch sie von allen Funktionen direkt verändert werden kann
    string name;

    //Problem: Attribut befindet sich in Public wodurch sie von allen Funktionen direkt verändert werden kann
    double price;

    //Problem: Attribut befindet sich in Public wodurch sie von allen Funktionen direkt verändert werden kann
    int stock;

    string* category;//wird das benötigt?

    //Problem: Attribut befindet sich in Public wodurch sie von allen Funktionen direkt verändert werden kann
    int id;

    Article(string name, double price, int stock, string category, int id) {
        //Name wird nicht mit Attribut "name" initializiert (Shaddowing)
        name = name;

        //Price wird nicht mit Attribut "price" initializiert (Shaddowing)
        price = price;

        //Stock wird nicht mit Attribut "stock" initializiert (Shaddowing)
        stock = stock;
        
        this->id = id;
        this->category = new string;
        *this->category = category;
    }

    void setPrice(double price) {
        price = price;
    }

    void sell(int amount) {
        stock = stock - amount;
    }

    void restock(int amount) {
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}