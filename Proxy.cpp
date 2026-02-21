#include <iostream>

using namespace std;

class RealImage {
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk(); // Load the image from disk when the RealImage is created
    }
    void display() {
        cout << "Displaying " << filename << endl; // Display the image
    }
private:
    std::string filename; // Filename of the image
    void loadFromDisk() {
        cout << "Loading " << filename << " from disk" << endl; // Simulate loading the image from disk
    }
};

class ProxyImage {
public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}
    ~ProxyImage() {
        delete realImage; // Clean up the RealImage if it was created
    }
    void display() {
        if (realImage == nullptr) {
            realImage = new RealImage(filename); // Create the RealImage only when it's needed
        }
        realImage->display(); // Display the image using the RealImage
    }
private:
    std::string filename; // Filename of the image
    RealImage* realImage; // Pointer to the RealImage, initially null
};

int main() {
    std::cout << "Proxy pattern example!" << std::endl;
    ProxyImage proxyImage("test_image.jpg"); // Create a ProxyImage with the filename
    proxyImage.display(); // Display the image (loads from disk and then displays)
    proxyImage.display(); // Display the image again (should not load from disk this time)
    return 0;
}