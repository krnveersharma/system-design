// The Composite Design Pattern is a structural design pattern 
// that lets you treat individual objects and compositions of objects uniformly. 
// It's often used to represent part-whole hierarchies like trees

// EXAMPLE
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// Component
class FileSystemEntity {
public:
    virtual void display(int indent = 0) = 0;
    virtual ~FileSystemEntity() = default;
};

// Leaf - File
class File : public FileSystemEntity {
    string name;
public:
    File(const string& name) : name(name) {}
    void display(int indent = 0) override {
        cout << string(indent, ' ') << "📄 " << name << endl;
    }
};

// Composite - Folder
class Folder : public FileSystemEntity {
    string name;
    vector<shared_ptr<FileSystemEntity>> children;
public:
    Folder(const string& name) : name(name) {}

    void add(const shared_ptr<FileSystemEntity>& entity) {
        children.push_back(entity);
    }

    void display(int indent = 0) override {
        cout << string(indent, ' ') << "📁 " << name << endl;
        for (const auto& child : children) {
            child->display(indent + 4);
        }
    }
};

int main() {
    auto file1 = make_shared<File>("file1.txt");
    auto file2 = make_shared<File>("file2.txt");
    auto file3 = make_shared<File>("file3.txt");
    auto file4 = make_shared<File>("file4.txt");

    auto subFolder = make_shared<Folder>("SubFolder");
    subFolder->add(file3);
    subFolder->add(file4);

    auto rootFolder = make_shared<Folder>("RootFolder");
    rootFolder->add(file1);
    rootFolder->add(file2);
    rootFolder->add(subFolder);

    rootFolder->display();

    return 0;
}

// ADVANTAGES
//1. Uniformity
//2. Extensibility
//3. Simplified code

