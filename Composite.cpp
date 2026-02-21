#include <iostream>
#include <vector>
using namespace std;

class interface {
public:
    virtual void size() = 0; // Pure virtual function to be implemented by concrete components
    virtual ~interface() {} // Virtual destructor for proper cleanup
};

class File : public interface {
public:
    void size() override {
        cout << "File size: 10KB" << endl; // Example implementation of size for a file
    }
};

class Folder : public interface {
public:
    void size() override {
        for (interface* child : children) {
            child->size(); // Call size on each child component (file or folder)
        }
    }
    void add(interface* component) {
        children.push_back(component); // Add a child component (file or folder) to the folder
    }
private:
    vector<interface*> children; // Vector to hold child components (files and folders)
};

int main() {
    std::cout << "Composite pattern example!" << std::endl;
    File* file1 = new File(); // Create a file component
    File* file2 = new File(); // Create another file component
    file1->size(); // Call size on file1
    file2->size(); // Call size on file2
    Folder* folder1 = new Folder(); // Create a folder component
    folder1->add(file1); // Add file1 to folder1
    folder1->add(file2); // Add file2 to folder1
    Folder* rootFolder = new Folder(); // Create a root folder component
    rootFolder->add(folder1); // Add folder1 to the root folder
    cout << "Total size of root folder: " << endl;
    rootFolder->size(); // Call size on the root folder, which will call size on all child components
    delete file1; // Clean up file1
    delete file2; // Clean up file2
    delete folder1; // Clean up folder1
    delete rootFolder; // Clean up rootFolder
    return 0;
}