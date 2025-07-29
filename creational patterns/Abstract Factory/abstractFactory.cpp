#include<iostream>
using namespace std;

class Chair{
public:
    virtual void SitOn()=0;
    virtual ~Chair() = default;
};

class Sofa{
public:
    virtual void lieOn()=0;
    virtual ~Sofa() = default;
};

class ModernChair:public Chair{
public:
    void SitOn() override{
        cout<<"Modern chair sit on"<<endl;
    }
};

class OldChair:public Chair{
public:
    void SitOn() override{
        cout<<"Old chair sit on"<<endl;
    }
};


class ModernSofa:public Sofa{
public:
    void lieOn() override{
        cout<<"Modern sofa sit on"<<endl;
    }
};

class OldSofa:public Sofa{
public:
    void lieOn() override{
        cout<<"Old sofa sit on"<<endl;
    }
};

class FurnitureFactory {
public:
    virtual Chair* createChair()=0;
    virtual Sofa* createSofa()=0;
};


class ModernFactory:public FurnitureFactory{
public:
    Chair* createChair() override{
        return new ModernChair();
    }
    Sofa* createSofa() override{
        return new ModernSofa();
    }
};

class OldFactory:public FurnitureFactory{
public:
    Chair* createChair() override{
        return new OldChair();
    }
    Sofa* createSofa() override{
        return new OldSofa();
    }
};

int main() {
    FurnitureFactory* factory = new ModernFactory();
    Chair* chair = factory->createChair();
    Sofa* sofa = factory->createSofa();

    chair->SitOn();
    sofa->lieOn();

    delete chair;
    delete sofa;
    delete factory;

    return 0;
}
