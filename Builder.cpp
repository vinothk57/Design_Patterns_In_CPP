#include <iostream>

using namespace std;

class Builder {
public:
    virtual void buildPartA() = 0; // Pure virtual function to build part A
    virtual void buildPartB() = 0; // Pure virtual function to build part B
    virtual ~Builder() {} // Virtual destructor
};

class ConcreteBuilder : public Builder {
public:
    void buildPartA() override {
        cout << "Building Part A" << endl;
    }
    void buildPartB() override {
        cout << "Building Part B" << endl;
    }
};

class Director {
public:
    void constructProductA(Builder* builder) {
        cout << "Constructing Product A" << endl;
        builder->buildPartA(); // Construct part A
    }
    void constructProductAB(Builder* builder) {
        cout << "Constructing Product AB" << endl;
        builder->buildPartA(); // Construct part B
        builder->buildPartB(); // Construct part A
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