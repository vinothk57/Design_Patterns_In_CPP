#include <iostream>
using namespace std;

class Car {
public:
    virtual void drive() = 0; // Pure virtual function
    virtual ~Car() {} // Virtual destructor
};

class Sedan : public Car {
public:
    void drive() override {
        cout << "Driving a Sedan" << endl;
    }
};

class Truck : public Car {
public:
    void drive() override {
        cout << "Driving a Truck" << endl;
    }
};    

class VehicleFactory {
    public:
    virtual Car* createVehicle() = 0; // Pure virtual function to create a car
};

class SedanFactory : public VehicleFactory {
public:
    Car* createVehicle() override {
        return new Sedan(); // Create and return a Sedan
    }
};
class TruckFactory : public VehicleFactory {
public:
    Car* createVehicle() override {
        return new Truck(); // Create and return a Truck
    }
};

int main() {
    std::cout << "Abstract Factory pattern example!" << std::endl;
    VehicleFactory* sedanFactory = new SedanFactory();
    Car* sedan = sedanFactory->createVehicle(); // Create a Sedan using the factory
    sedan->drive(); // Drive the Sedan
    delete sedan; // Clean up
    delete sedanFactory; // Clean up the factory
    VehicleFactory* truckFactory = new TruckFactory();
    Car* truck = truckFactory->createVehicle(); // Create a Truck using the factory
    truck->drive(); // Drive the Truck
    delete truck; // Clean up
    delete truckFactory; // Clean up the factory
    return 0;
}