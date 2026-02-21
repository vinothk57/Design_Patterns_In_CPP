#include <iostream>

using namespace std;

class AnalogClock {
public:
    void displayTime(int hours, int minutes) {
        cout << "Analog Clock: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }
};

class ClockAdapter {
public:
    ClockAdapter(AnalogClock* analogClock) : analogClock(analogClock) {}
    void showTime(int hours, int minutes){
        analogClock->displayTime(hours, minutes); // Adapt the AnalogClock's displayTime method to showTime
    }
private:
    AnalogClock* analogClock; // Pointer to the adaptee (AnalogClock)
};

int main() {
    std::cout << "Adapter pattern example!" << std::endl;
    AnalogClock analogClock; // Create an instance of the adaptee (AnalogClock)
    ClockAdapter clockAdapter(&analogClock); // Create an adapter for the AnalogClock
    clockAdapter.showTime(10, 30); // Use the adapter to show time in a compatible way
    return 0;
}