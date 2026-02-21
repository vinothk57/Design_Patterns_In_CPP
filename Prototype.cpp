#include <iostream>

using namespace std;

class Prototype {
public:
    virtual Prototype* clone() const = 0; // Pure virtual function for cloning
    virtual void show() const = 0; // Pure virtual function to display the prototype
    virtual ~Prototype() {} // Virtual destructor
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(const std::string& name) : name(name) {} // Constructor to initialize the prototype
    Prototype* clone() const override {
        return new ConcretePrototype(*this); // Create a copy of the current object
    }
    void show() const override {
        cout << "ConcretePrototype: " << name << endl; // Display the prototype's name
    }
private:
    std::string name; // Name of the prototype
};

class Client {
public:
    void createPrototype() {
        Prototype* prototype1 = new ConcretePrototype("Prototype 1"); // Create a new prototype
        prototype1->show(); // Display the original prototype
        Prototype* prototype2 = prototype1->clone(); // Clone the original prototype
        prototype2->show(); // Display the cloned prototype
        delete prototype1; // Clean up the original prototype
        delete prototype2; // Clean up the cloned prototype
    }
};

int main() {
    Client client;
    client.createPrototype(); // Create and display prototypes
    return 0;
}