#include <iostream>
using namespace std;

class TV {
public:
    void on() {
        cout << "TV is ON" << endl;
    }
    void off() {
        cout << "TV is OFF" << endl;
    }
};

class SoundSystem {
public:
    void on() {
        cout << "Sound System is ON" << endl;
    }
    void off() {
        cout << "Sound System is OFF" << endl;
    }
};

class Lights {
public:
    void on() {
        cout << "Lights are ON" << endl;
    }
    void off() {
        cout << "Lights are OFF" << endl;
    }
};

class HomeTheaterFacade {
public:
    HomeTheaterFacade(TV* tv, SoundSystem* soundSystem, Lights* lights)

        : tv(tv), soundSystem(soundSystem), lights(lights) {}
    
    void watchMovie() {
        cout << "Get ready to watch a movie..." << endl;
        lights->off();
        tv->on();
        soundSystem->on();
    }
    
    void endMovie() {
        cout << "Shutting down the home theater..." << endl;
        soundSystem->off();
        tv->off();
        lights->on();
    }
private:
    TV* tv; // Pointer to the TV subsystem
    SoundSystem* soundSystem; // Pointer to the Sound System subsystem
    Lights* lights; // Pointer to the Lights subsystem
};

int main() {
    std::cout << "Facade pattern example!" << std::endl;
    TV* tv = new TV(); // Create an instance of the TV subsystem
    SoundSystem* soundSystem = new SoundSystem(); // Create an instance of the Sound System subsystem
    Lights* lights = new Lights(); // Create an instance of the Lights subsystem
    HomeTheaterFacade* homeTheater = new HomeTheaterFacade(tv, soundSystem, lights); // Create the Facade with the subsystems
    homeTheater->watchMovie(); // Use the Facade to watch a movie
    homeTheater->endMovie(); // Use the Facade to end the movie
    delete homeTheater; // Clean up the Facade
    delete tv; // Clean up the TV subsystem
    delete soundSystem; // Clean up the Sound System subsystem
    delete lights; // Clean up the Lights subsystem
    return 0;
}