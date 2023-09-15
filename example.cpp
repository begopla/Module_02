#include <iostream>

class MyClass {
private:
    int* data; // Example member variable

public:
    // Default constructor
    MyClass() : data(nullptr) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(nullptr) {
        if (other.data) {
            data = new int(*other.data);
        }
        std::cout << "Copy constructor called." << std::endl;
    }

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) { // Self-assignment check
            delete data; // Clean up existing data

            if (other.data) {
                data = new int(*other.data);
            } else {
                data = nullptr;
            }
        }
        std::cout << "Copy assignment operator called." << std::endl;
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data; // Clean up allocated data
        std::cout << "Destructor called." << std::endl;
    }

    // Example member function
    void setData(int value) {
        if (!data) {
            data = new int(value);
        } else {
            *data = value;
        }
    }

    // Example member function
    int getData() const {
        return (data) ? *data : 0;
    }
};

int main() {
    MyClass obj1;
    obj1.setData(42);

    MyClass obj2 = obj1; // Copy constructor
    MyClass obj3;
    obj3 = obj1; // Copy assignment operator

    std::cout << "obj1 data: " << obj1.getData() << std::endl;
    std::cout << "obj2 data: " << obj2.getData() << std::endl;
    std::cout << "obj3 data: " << obj3.getData() << std::endl;

    return 0;
}
