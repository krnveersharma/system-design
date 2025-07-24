#include <iostream>
using namespace std;

class Vehicle {
public:
    int tires;
    string color;

    virtual void display() {
        cout << "Vehicle with " << tires << " tires and color " << color << endl;
    }

    virtual ~Vehicle() {}  // Virtual destructor for proper cleanup
};

class Bike : public Vehicle {
public:
    Bike() {
        tires = 2;
        color = "red";
    }
};

class Car : public Vehicle {
public:
    Car() {
        tires = 4;
        color = "blue";
    }
};

class VehicleFactory {
public:
    Vehicle* DecideVehicle(const string& name) {
        if (name == "car") {
            return new Car();
        } else {
            return new Bike();
        }
    }
};

int main() {
    VehicleFactory factory;

Vehicle* v1;
    string vehicle;
    cin>>vehicle;
    // if(vehicle=="car"){
    //     v1=new Car()
    // }
    // else{
    //     v1=new Bike;
    // }  instead of deciding here make new facotry to decide internally

    Vehicle* v1 = factory.DecideVehicle(vehicle);
    v1->display();  


    delete v1;
    return 0;
}
