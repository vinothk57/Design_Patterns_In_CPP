#include <iostream>

using namespace std;

class Product {
public:
    void addPart(const std::string& part) {
        cout << "Adding part: " << part << endl;
        name.append(part + " ");
    }
    void show() {
        cout << "Product: " << name << endl;
    }
private:
    std::string name;
};

class Builder {
public:
    virtual void startBuilding() = 0; // Pure virtual function to start building
    virtual void buildPartA() = 0; // Pure virtual function to build part A
    virtual void buildPartB() = 0; // Pure virtual function to build part B
    virtual Product* getProduct() = 0; // Pure virtual function to get the final product
    virtual ~Builder() {} // Virtual destructor
};

class ConcreteBuilder : public Builder {
public:
    void startBuilding() override {
        cout << "Starting to build the product" << endl;
        product = new Product(); // Initialize the product
    }
    void buildPartA() override {
        cout << "Building Part A" << endl;
        product->addPart("Part A"); // Add part A to the product
    }
    void buildPartB() override {
        cout << "Building Part B" << endl;
        product->addPart("Part B"); // Add part B to the product
    }
    Product* getProduct() override {
        product->show(); // Show the final product
        return product; // Return the constructed product
    }
private:
    Product* product;
};

class Director {
public:
    void constructProductA(Builder* builder) {
        cout << "Constructing Product A" << endl;
        builder->startBuilding(); // Start building the product
        builder->buildPartA(); // Construct part A
        builder->getProduct(); // Get the final product
    }
    void constructProductAB(Builder* builder) {
        cout << "Constructing Product AB" << endl;
        builder->startBuilding(); // Start building the product
        builder->buildPartA(); // Construct part B
        builder->buildPartB(); // Construct part A
        builder->getProduct(); // Get the final product
    }
};

int main() {
    cout << "Builder pattern example!" << endl;
    Builder* builder = new ConcreteBuilder();
    Director director;
    director.constructProductA(builder); // Construct product A using the builder
    director.constructProductAB(builder); // Construct product AB using the builder
    delete builder; // Clean up
    return 0;
}