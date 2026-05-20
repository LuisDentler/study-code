# C++ Lernzettel - Programmierung & Konventionen

## 1. C++ Coding Conventions

### Allgemeines
- Schreibe Code für Menschen zuerst, für den Compiler zweitens.
- Bevorzuge klare und einfache Lösungen.
- Vermeide cleveren, schwer lesbaren Code.
- Verwende immer `{}` bei `if`, `for`, `while` und `else`.
- Vermeide `using namespace std;` in Header-Dateien und globalen Bereichen.

### Formatierung
- 4 Leerzeichen pro Einrückung oder 1 Tab, aber nicht beides mischen.
- Eine Anweisung pro Zeile.
- Linien sollten ungefähr unter 100 Zeichen bleiben.
- Eine Leerzeile zwischen logischen Blöcken.

### Dateien / Module
- Ein Modul = eine Header-Datei (`.hpp`) + eine Quell-Datei (`.cpp`).
- Header-Dateien enthalten Schnittstellen, nicht große Implementierungen.
- Dateinamen sollten den Typ oder Zweck klar beschreiben.

### Header-Dateien
- Nutze Include-Guards oder `#pragma once`.
- Keine globalen Objektdefinitionen im Header.
- Nur das einbinden, was wirklich benötigt wird.

### Kommentare
- Beschreibe den Zweck und die Annahmen, nicht den Code selbst.
- Dokumentiere öffentliche Funktionen mit Parametern und Rückgabewerten.
- Vermeide Kommentare wie `// i++`.

### Variablen
- Initialisiere Variablen sofort.
- Eine Deklaration pro Zeile.
- Halte den Gültigkeitsbereich so klein wie möglich.

---

## 2. Naming Conventions (Schreibweise)

### Regeln
- Variablen / Parameter: `lower_snake_case` oder `camelCase`
- Funktionen / Methoden: `lower_snake_case` oder `camelCase`, möglichst Verben
- Namespaces: `lower_snake_case`
- Konstanten: `UPPER_SNAKE_CASE`
- Klassen / Structs / Enums: `PascalCase`
- Zeiger: mit `p_` oder `ptr_` beginnen

**Wichtig:** Wähle eine Variante und bleibe konsistent.

### Gute Beispiele
```cpp
class MotorController
{
private:
    int current_speed_rpm;

public:
    void set_target_speed(int target_speed_rpm);
};

const int MAX_BUFFER_SIZE = 128;
```

### Schlechte Beispiele
```cpp
class motorcontroller
{
private:
    int s;

public:
    void st(int x);
};

const int x = 128;
```

### Beispiel für Variablen und Funktionen
```cpp
int user_age = 25;
double temperature_celsius = 23.5;
void calculate_result() { }
std::string first_name = "John";
```

### Konstanten (UPPER_SNAKE_CASE)
```cpp
const int MAX_USERS = 100;
const double PI = 3.14159;
const std::string DEFAULT_NAME = "Unknown";
```

### Klassen (PascalCase)
```cpp
class UserManager { };
class VehicleController { };
struct DataPoint { };
```

### Private Membervariablen (mit Unterstrich oder m_ Präfix)
```cpp
class Calculator
{
private:
    int _result;           // oder
    int m_result;          // beide Varianten sind ok
};
```

### Konstante Objekte
```cpp
const int MAX_SIZE = 100;
const std::string DATABASE_NAME = "mydb.db";
```

---

## 3. Das `const` Keyword - WANN und WARUM

### 2.1 Konstante Variablen (unveränderbar)
```cpp
const int MAX_AGE = 120;        // Wert kann NICHT geändert werden
MAX_AGE = 150;                  // ❌ FEHLER!

const double PI = 3.14159;
PI = 3.14;                      // ❌ FEHLER!
```

**WANN:** Wenn ein Wert sich nie ändern darf (Konstanten, Magic Numbers)

### 2.2 const bei Funktionsparametern
```cpp
// Parameter soll NICHT verändert werden
void printName(const std::string& name) {
    name = "Other";             // ❌ FEHLER!
    std::cout << name << std::endl;
}

// Parameter kann verändert werden
void modifyValue(int& value) {
    value = 100;                // ✅ OK
}
```

**WANN:** Parameter-Schreibzugriff verbieten → Sicherheit & Klarheit

### 2.3 const Memberfunktionen
```cpp
class BankAccount {
private:
    double balance = 1000.0;

public:
    // Diese Funktion ändert KEINE Membervariablen
    double getBalance() const {
        return balance;         // ✅ Lesbar
        // balance = 500;       // ❌ FEHLER in const Funktion!
    }

    // Diese Funktion ÄNDERT Membervariablen
    void deposit(double amount) {
        balance += amount;      // ✅ OK
    }
};
```

**WANN:** Getter-Funktionen, die nur lesen, nicht schreiben

### 2.4 const Zeiger und Referenzen
```cpp
// Zeiger ist const, Wert kann geändert werden
int x = 10;
int* const ptr1 = &x;
*ptr1 = 20;                     // ✅ OK
ptr1 = nullptr;                 // ❌ FEHLER!

// Wert ist const, Zeiger kann sich ändern
const int* ptr2 = &x;
*ptr2 = 20;                     // ❌ FEHLER!
ptr2 = &y;                      // ✅ OK

// Beides ist const
const int* const ptr3 = &x;
*ptr3 = 20;                     // ❌ FEHLER!
ptr3 = &y;                      // ❌ FEHLER!
```

**Eselsbrücke:** `const` gilt für das Wort LINKS daneben
- `const int*` → int ist const
- `int* const` → Zeiger ist const

### 2.5 const Referenzen
```cpp
void process_data(const std::vector<int>& data) {
    // data kann NICHT verändert werden
    // aber auch kein Kopieren (effizient!)
    data[0] = 100;              // ❌ FEHLER!
}

// Alternative ohne const (WARNUNG! Macht Kopie)
void process_data(std::vector<int> data) {
    data[0] = 100;              // ✅ OK, aber ineffizient
}
```

**WANN:** Parameter sind große Objekte (Vector, String) → ohne Kopieren

---

## 3. Pointer vs. Referenzen

### Zeiger (Pointer)
```cpp
int x = 10;
int y = 20;
int* ptr_x = &x;            // Adresse speichern
std::cout << *ptr_x;        // 10 (dereferenzieren)
ptr_x = nullptr;            // Kann NULL sein
ptr_x = &y;                 // Kann neu zugewiesen werden

// In Funktionen
void modify_with_pointer(int* ptr_value) {
    if (ptr_value != nullptr) {
        *ptr_value = 100;
    }
}
```

**Wann:** Optionale Werte (kann nullptr sein), dynamisches Speichern

### Referenzen
```cpp
int x = 10;
int& ref = x;               // Alias für x
ref = 20;                   // x wird auf 20 gesetzt
// ref = &y;                // ❌ FEHLER! Kann nicht neu zugewiesen werden

// In Funktionen
void modify_with_reference(int& value) {
    value = 100;            // x wird verändert
}

int main() {
    int num = 5;
    modify_with_reference(num);
    std::cout << num;       // 100
}
```

**Wann:** Normaler Gebrauch (schnell, sicher, nicht optional)

### Vergleich
| | Zeiger | Referenz |
|---|---|---|
| NULL möglich | ✅ Ja | ❌ Nein |
| Neu zuweisen | ✅ Ja | ❌ Nein |
| Dereferenzierung | `*ptr` | direkt nutzbar |
| Sicherheit | Niedrig | Hoch |
| Performance | Gleich | Gleich |

---

## 4. Memory Management

### Stack vs. Heap
```cpp
// STACK - automatisch freigegeben
int x = 10;                     // Stack
std::string name = "John";      // Stack
std::vector<int> numbers = {1, 2, 3};  // Stack

// HEAP - manuell oder mit Smart Pointer freigeben
int* ptr = new int(10);         // ❌ Muss delete werden!
delete ptr;                     // Speicher freigeben
ptr = nullptr;                  // Sicherheit

// HEAP mit Smart Pointer (EMPFOHLEN)
std::unique_ptr<int> ptr1(new int(10));        // Automatisch freigegeben
std::shared_ptr<int> ptr2 = std::make_shared<int>(10);
// Kein delete nötig!
```

**Faustregel:** 
- Einfache Werte → Stack
- Große Datenmengen → Stack mit Vector/String
- Nur wenn nötig (z.B. polymorphe Objekte) → Smart Pointer

---

## 5. Funktionen - Besonderheiten

### Default Parameter
```cpp
void greet(const std::string& name = "Gast") {
    std::cout << "Hallo " << name << std::endl;
}

greet();                // "Hallo Gast"
greet("Anna");          // "Hallo Anna"
```

### Pass by Value vs. Reference
```cpp
// By Value - Kopie wird gemacht
void modifyValue(int x) {
    x = 100;            // Original unverändert
}

// By Reference - Original wird verändert
void modifyReference(int& x) {
    x = 100;            // Original wird verändert
}

// By const Reference - effizient, ohne Änderungen
void readData(const std::string& str) {
    // Keine Kopie, nicht veränderbar
}
```

### Return Values
```cpp
// Rückgabe mit Kopie
std::string getName() {
    return "John";      // ✅ OK für kleine Werte
}

// Rückgabe mit Referenz (ACHTUNG! Darf nicht lokal sein)
const std::vector<int>& getVector() {
    static std::vector<int> data = {1, 2, 3};
    return data;        // ✅ OK (static)
    // std::vector<int> local = {1, 2, 3};
    // return local;    // ❌ FEHLER! (dangling reference)
}
```

---

## 6. Klassen und Objektorientierung

### Grundstruktur
```cpp
class Animal {
private:
    std::string name;
    int age;

public:
    Animal(const std::string& n, int a) : name(n), age(a) { }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        name = n;
    }

    virtual void speak() const {
        std::cout << name << " makes a sound" << std::endl;
    }

    virtual ~Animal() = default;  // wichtig bei Vererbung
};
```

### Vererbung und virtuelle Funktionen
```cpp
class Dog : public Animal {
public:
    Dog(const std::string& n, int a) : Animal(n, a) { }

    void speak() const override {
        std::cout << getName() << " says: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n, int a) : Animal(n, a) { }

    void speak() const override {
        std::cout << getName() << " says: Meow!" << std::endl;
    }
};
```

### Polymorphie - Laufzeitverhalten
```cpp
void make_animal_speak(const Animal& animal) {
    animal.speak();  // ruft die richtige Version zur Laufzeit auf
}

int main() {
    Dog dog("Bello", 3);
    Cat cat("Miez", 2);

    make_animal_speak(dog);   // Hund spricht
    make_animal_speak(cat);   // Katze spricht

    Animal* animal = new Dog("Fido", 4);
    animal->speak();          // virtuelle Funktion, ruft Dog::speak()
    delete animal;            // benötigt virtuellen Destruktor
}
```

### Pure Virtual Functions / Abstrakte Basis-Klasse
```cpp
class Shape {
public:
    virtual double area() const = 0;   // reine virtuelle Funktion
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) { }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};
```

**WANN:** Verwende eine abstrakte Basis-Klasse, wenn du eine gemeinsame Schnittstelle für unterschiedliche Klassen brauchst.

### `override` und `final`
- `override` zeigt klar an, dass die Funktion aus der Basisklasse überschrieben wird.
- `final` verhindert weitere Überschreibungen.

```cpp
class Base {
public:
    virtual void doWork() const {
        std::cout << "Base" << std::endl;
    }
};

class Derived final : public Base {
public:
    void doWork() const override {
        std::cout << "Derived" << std::endl;
    }
};
```

### Konstructor Initialisierungsliste (Wichtig!)
```cpp
class Person {
private:
    std::string name;
    int age;
    const int id;

public:
    Person(const std::string& n, int a, int i)
        : name(n), age(a), id(i) { }
};
```

**WANN:** Immer für const Member, Referenzen und Memberobjekte.

---

## 7. Header und Include Guards

### Header-Datei (beispiel.hpp)
```cpp
#ifndef BEISPIEL_HPP
#define BEISPIEL_HPP

#include <string>
#include <vector>

class Calculator {
public:
    int add(int a, int b) const;
    int subtract(int a, int b) const;
};

#endif  // BEISPIEL_HPP
```

### Implementation (beispiel.cpp)
```cpp
#include "beispiel.hpp"

int Calculator::add(int a, int b) const {
    return a + b;
}

int Calculator::subtract(int a, int b) const {
    return a - b;
}
```

### Include-Reihenfolge
```cpp
// 1. Zugehörige Header
#include "myclass.hpp"

// 2. Standard Library
#include <iostream>
#include <string>
#include <vector>

// 3. Third-Party Libraries (falls vorhanden)
// #include <boost/...>
```

---

## 8. Best Practices Zusammenfassung

### ✅ DO's
- ✅ `const` verwenden für unveränderbare Werte
- ✅ Referenzen statt Pointer für Parameter (wenn nicht optional)
- ✅ `const` Referenzen für große Objekte
- ✅ Header Guards oder `#pragma once`
- ✅ Member-Initialisierungsliste verwenden
- ✅ `nullptr` statt `NULL` oder `0`
- ✅ `override` bei Vererbung verwenden
- ✅ STL Container (vector, string) statt Arrays
- ✅ Smart Pointer (unique_ptr, shared_ptr) statt raw new/delete

### ❌ DON'Ts
- ❌ `using namespace std;` vermeiden
- ❌ Global Variablen meiden
- ❌ Magic Numbers verwenden (stattdessen const)
- ❌ Pointer für optionale Parameter (stattdessen std::optional)
- ❌ `new`/`delete` direktional (Smart Pointer nutzen)
- ❌ Nicht-const Getter
- ❌ Dangling Pointers/References (Wert verliert Gültigkeit)

---

## 9. Häufige Fehler

### Fehler 1: const vergessen
```cpp
// ❌ FALSCH
void printVector(std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";  // Warum nicht const?
    }
}

// ✅ RICHTIG
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
}
```

### Fehler 2: Dangling Reference
```cpp
// ❌ FALSCH
const std::string& getName() {
    std::string name = "John";
    return name;    // ❌ name wird nach return gelöscht!
}

// ✅ RICHTIG
const std::string& getName() {
    static std::string name = "John";
    return name;    // ✅ static existiert weiterhin
}

// ✅ ODER (besser)
std::string getName() {
    return "John";  // ✅ Kopie wird zurückgegeben
}
```

### Fehler 3: Pointer NULL-Check vergessen
```cpp
// ❌ FALSCH
void process(int* ptr) {
    std::cout << *ptr;  // Crash wenn ptr nullptr ist!
}

// ✅ RICHTIG
void process(int* ptr) {
    if (ptr != nullptr) {
        std::cout << *ptr;
    }
}

// ✅ ODER (besser)
void process(int& ref) {  // Referenz kann nicht nullptr sein
    std::cout << ref;
}
```

---

## 10. Checkliste für Code-Review

Vor dem Commit immer überprüfen:

- [ ] Alle Variablen haben sprechende Namen (camelCase)
- [ ] Konstanten sind mit UPPER_SNAKE_CASE benannt
- [ ] Magic Numbers sind durch const Variablen ersetzt
- [ ] Getter-Funktionen haben `const`
- [ ] Parameter-Referenzen sind `const` (wenn nicht modifiziert)
- [ ] Große Objekte werden als const Reference übergeben
- [ ] Header Guards sind vorhanden
- [ ] Keine `using namespace std;`
- [ ] Smart Pointer statt raw new/delete
- [ ] Override wird bei virtuellen Funktionen verwendet

---

## Weiterführende Konzepte

### Templates (Generische Programmierung)
```cpp
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

std::cout << maximum(5, 10) << std::endl;        // 10
std::cout << maximum(3.14, 2.71) << std::endl;   // 3.14
```

### Exception Handling
```cpp
try {
    if (value < 0) {
        throw std::invalid_argument("Negative Wert!");
    }
} catch (const std::invalid_argument& e) {
    std::cerr << "Fehler: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Unbekannter Fehler" << std::endl;
}
```

### std::optional (C++17)
```cpp
#include <optional>

std::optional<int> findUser(const std::string& name) {
    if (name == "admin") {
        return 1;           // User gefunden
    }
    return std::nullopt;    // User nicht gefunden
}

auto result = findUser("admin");
if (result.has_value()) {
    std::cout << result.value() << std::endl;
}
```

---

## Ressourcen

- [C++ Reference](https://en.cppreference.com/)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Modern C++ Best Practices](https://github.com/isocpp/CppCoreGuidelines)
