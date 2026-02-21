#include <iostream>
#include <thread>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton singleton_instance; // Guaranteed to be destroyed and instantiated on first use
        return singleton_instance;
    }

    ~Singleton() {
    }

    void getData() {
        cout << "Data value: " << data << endl;
    }

    void incrementData() {
        data++;
    }
private:   
    Singleton()
    {
        data = 0; // Initialize member variable
    } // Private constructor to prevent instantiation
    Singleton(const Singleton&) = delete; // Delete copy constructor
    Singleton& operator=(const Singleton&) = delete; // Delete copy assignment operator

    int data; // Example member variable
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Singleton& singleton_object = Singleton::getInstance(); // Access the singleton instance
    std::cout << "Initial data value: "  << std::endl;
    // Output initial value
    singleton_object.getData();
    singleton_object.incrementData(); // Increment the data value
    std::cout << "Data value after increment: " << std::endl;
    // Output incremented value
    singleton_object.getData();

    Singleton& another_singleton_object = Singleton::getInstance(); // Access the singleton instance again
    std::cout << "Data value from another reference: " << std::endl;
    // Output the same value to confirm it's the same instance
    another_singleton_object.getData();
    return 0;
}