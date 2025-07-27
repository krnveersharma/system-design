// Bridge is a structural design pattern 
// that lets you split a large class or a 
// set of closely related classes into two 
// separate hierarchies—abstraction and implementationv
// which can be developed independently of each other.


// WHEN TO USE
// 1. You want to be able to switch between implementations at runtime.

// 2. You want to reduce code duplication when you have multiple variations of abstractions and implementations.


// EXAMPLE

#include <iostream>
#include <memory>
using namespace std;

// Implementor
class Color {
public:
    virtual string getColor() = 0;
    virtual ~Color() = default;
};

// ConcreteImplementor 1
class RedColor : public Color {
public:
    string getColor() override {
        return "Red";
    }
};

// ConcreteImplementor 2
class BlueColor : public Color {
public:
    string getColor() override {
        return "Blue";
    }
};

// Abstraction
class Shape {
protected:
    shared_ptr<Color> color;

public:
    Shape(shared_ptr<Color> c) : color(c) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// RefinedAbstraction 1
class Circle : public Shape {
public:
    Circle(shared_ptr<Color> c) : Shape(c) {}

    void draw() override {
        cout << "Drawing a " << color->getColor() << " Circle" << endl;
    }
};

// RefinedAbstraction 2
class Square : public Shape {
public:
    Square(shared_ptr<Color> c) : Shape(c) {}

    void draw() override {
        cout << "Drawing a " << color->getColor() << " Square" << endl;
    }
};

// ---- Usage ----
int main() {
    auto red = make_shared<RedColor>();
    auto blue = make_shared<BlueColor>();

    Circle redCircle(red);
    redCircle.draw();      // Output: Drawing a Red Circle

    Square blueSquare(blue);
    blueSquare.draw();     // Output: Drawing a Blue Square

    Circle blueCircle(blue);
    blueCircle.draw();     // Output: Drawing a Blue Circle

    return 0;
}



// WRONG EXAMPLE

#include <iostream>
using namespace std;

// One-off combinations of shape and color
class RedCircle {
public:
    void draw() {
        cout << "Drawing a Red Circle" << endl;
    }
};

class BlueCircle {
public:
    void draw() {
        cout << "Drawing a Blue Circle" << endl;
    }
};

class RedSquare {
public:
    void draw() {
        cout << "Drawing a Red Square" << endl;
    }
};

class BlueSquare {
public:
    void draw() {
        cout << "Drawing a Blue Square" << endl;
    }
};

// ---- Usage ----
int main() {
    RedCircle rc;
    rc.draw();         // Drawing a Red Circle

    BlueSquare bs;
    bs.draw();         // Drawing a Blue Square

    return 0;
}


// 1.Now consider there are 12 colors and 5 shapes, 
// then we have to make total of 12* 5=60 classes

// 2.No flexibility

//3. not open for extenion

//4. hard to maintain