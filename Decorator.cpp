#include <iostream>
using namespace std;

class Pizza {
public:
    virtual int prize() = 0; // Pure virtual function to prepare the pizza
    virtual ~Pizza() {} // Virtual destructor
};

class SimplyVeg : public Pizza {
public:
    int prize() override {
        return 5;
    }
};

class VegDelight : public Pizza {
public:
    VegDelight(Pizza* pizza) : pizza(pizza) {
        cout << "Preparing Veg Delight Pizza" << endl; // Constructor to indicate preparation of Veg Delight Pizza
    }
    int prize() override {
        return pizza->prize() + 2;
    }
private:
    Pizza* pizza; // Pointer to the base pizza (Simply Veg)
};

class ExtraCheese : public Pizza {
public:
    ExtraCheese(Pizza* pizza) : pizza(pizza) {
        cout << "Adding Extra Cheese" << endl; // Constructor to indicate adding extra cheese
    }
    int prize() override {
        return pizza->prize() + 1;
    }
private:
    Pizza* pizza; // Pointer to the base pizza (Simply Veg or Veg Delight)
};

int main() {
    std::cout << "Decorator pattern example!" << std::endl;
    Pizza* simplyVeg = new SimplyVeg(); // Create a Simply Veg Pizza
    std::cout << "Simply Veg Pizza price: $" << simplyVeg->prize() << std::endl; // Display the price of Simply Veg Pizza
    Pizza* vegDelight = new VegDelight(simplyVeg); // Decorate the Simply Veg Pizza to create Veg Delight Pizza
    std::cout << "Veg Delight Pizza price: $" << vegDelight->prize() << std::endl; // Display the price of Veg Delight Pizza

    Pizza* extraCheeseVegDelight = new ExtraCheese(vegDelight); // Decorate the Veg Delight Pizza to add Extra Cheese
    std::cout << "Veg Delight Pizza with Extra Cheese price: $" << extraCheeseVegDelight->prize() << std::endl; // Display the price of Veg Delight Pizza with Extra Cheese
    delete simplyVeg; // Clean up the Simply Veg Pizza
    delete vegDelight; // Clean up the Veg Delight Pizza
    delete extraCheeseVegDelight; // Clean up the Veg Delight Pizza with Extra Cheese
    return 0;
}