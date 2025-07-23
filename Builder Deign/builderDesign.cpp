#include<iostream>
using namespace std;

class Computer{
private:
    string cpu,memory,ram;
public:
    void setCpu(string cpu){
        this->cpu=cpu;
    }
    void setMemory(string memory){
        this->memory=memory;
    }
    void setRam(string ram){
        this->ram=ram;
    }
     void display() {
        cout << "CPU: " << cpu << ", Memory: " << memory << ", RAM: " << ram << endl;
    }
};

class ComputerBuilder{
public: 
    virtual void setCpu (string cpu)=0;
    virtual void setMemory (string memory)=0;
    virtual void setRam (string ram)=0;
    virtual Computer* getResult ()=0;
};

class DellComputerBuilder: public ComputerBuilder{
public:
    Computer* computer;
    DellComputerBuilder(){
        computer=new Computer();
    }
    void setCpu(string cpu) override{
        computer->setCpu("i7");
    }
    void setMemory(string memory) override{
        computer->setMemory("1Tb");
    }
    void setRam(string cpu) override{
        computer->setRam("16GB");
    }
    Computer* getResult() override{
        return computer;
    }
};

class MacComputerBuilder: public ComputerBuilder{
public:
    Computer* computer;
     MacComputerBuilder(){
        computer=new Computer();
    }
    void setCpu(string cpu) override{
        computer->setCpu("M4");
    }
    void setMemory(string memory) override{
        computer->setMemory("1Tb");
    }
    void setRam(string cpu) override{
        computer->setRam("16GB");
    }
    Computer* getResult() override{
        return computer;
    }
};

class Director {
public:
    void construct(ComputerBuilder* builder) {
        builder->setCpu("i7");
        builder->setMemory("1TB");
        builder->setRam("16GB");
    }
};

int main() {
    Director director;

    DellComputerBuilder dellBuilder;
    director.construct(&dellBuilder);
    Computer* dell = dellBuilder.getResult();
    dell->display();

    MacComputerBuilder macBuilder;
    director.construct(&macBuilder);
    Computer* mac = macBuilder.getResult();
    mac->display();

    delete dell;
    delete mac;

    return 0;
}