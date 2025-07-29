// The decorator pattern is a structural design pattern
// that enables dynamic addition of responsibilities or behaviors to individual objects, without altering their underlying class structure. 
// This pattern is especially useful for extending the functionalities of objects 
// in a flexible and reusable way, adhering to the open/closed principle

//KEY CONCEPTS

//1. Component Interface: Defines a common interface for both concrete components and decorators, specifying the operations that can be performed.
//2. Concrete Component: Implements the component interface; represents the basic object to be decorated.
//3. Decorator: Abstract class implementing the component interface and containing a reference to a component. It wraps the component and delegates work to it.
//4. Concrete Decorator: Extends the decorator and adds specific behavior before or after delegating operations to the component object


#include<iostream>
using namespace std;

// Component interface
class IceCream{
public:
    virtual string getDescription() =0;
    virtual double cost()  = 0;
};

// Concrete Component
class VanillaIcecream: public IceCream{
public:
    string getDescription() override{
        return "Vanilla Ice Cream";
    }
    double cost() override{
        return 160.0;
    }
};

// Decorator - abstract class
class IceCreamDecorator: public IceCream{
protected:
    IceCream* iceCream;
public:
    IceCreamDecorator(IceCream* ic) : iceCream(ic){}
    string getDescription()  override{ 
        return iceCream->getDescription();
    }
    double cost()  override {
         return iceCream->cost(); 
    }
};

// Concrete Decorators
class ChocolateDecorator: public IceCreamDecorator{
public:
    ChocolateDecorator(IceCream* ic): IceCreamDecorator(ic){}
    string getDescription()  override{
        return iceCream->getDescription()+" with chocoloate";
    }
    double cost()  override{
        return iceCream->cost()+100.0;
    }
};

class CaramelDecorator: public IceCreamDecorator{
public:
    CaramelDecorator(IceCream* ic): IceCreamDecorator(ic){}
    string getDescription()  override{
        return iceCream->getDescription()+" with caramel";
    }
    double cost()  override{
        return iceCream->cost()+150.0;
    }
};


int main(){
    IceCream* vanillaIceCream=new VanillaIcecream();
    IceCream* withChocolate=new ChocolateDecorator(vanillaIceCream);
    cout<<withChocolate->getDescription()<<endl;

    IceCream* withCaramel=new CaramelDecorator(vanillaIceCream);
    cout<<withCaramel->getDescription()<<endl;

    IceCream* VanillaChocolateCaramel=new CaramelDecorator(withChocolate);
    cout<<VanillaChocolateCaramel->getDescription()<<" and cost is: "<<VanillaChocolateCaramel->cost()<<endl;
    return 0;
}