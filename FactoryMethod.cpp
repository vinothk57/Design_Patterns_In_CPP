#include <iostream>

class Product {
public:
    virtual void use() = 0; // Pure virtual function
    virtual ~Product() {} // Virtual destructor
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class Factory {
public:
    static Product* createProduct(const std::string& type) {
        if (type == "A") {
            return new ConcreteProductA();
        } else if (type == "B") {
            return new ConcreteProductB();
        } else {
            return nullptr; // Return nullptr for unknown product types
        }
    }
};

int main() {
    std::cout << "Factory Method pattern example!" << std::endl;

    Product* productA = Factory::createProduct("A");
    if (productA) {
        productA->use();
        delete productA; // Clean up
    }
    Product* productB = Factory::createProduct("B");
    if (productB) {
        productB->use();
        delete productB; // Clean up
    }
    return 0;
}