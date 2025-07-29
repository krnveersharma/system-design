// The Proxy design pattern in C++ is a structural design pattern 
// that provides a surrogate or placeholder object for another object,
// called the real service object, to control access to it. 
// The proxy has the same interface as the real object, making it 
// interchangeable for the client. It intercepts calls from the 
// client, can perform additional tasks like access control, lazy loading

// Key Concepts
// 1.Subject Interface: Defines the common interface for both the real object (RealSubject) and the proxy.
// 2.Real Object (RealSubject): Implements the core functionality.
// 3.Proxy Object: Implements the same interface and holds a reference to the real object. 
//     It controls access, creates the real object on demand (lazy initialization), or adds extra behavior.

#include<iostream>
using namespace std;

class BankAccount{
public:
    virtual void Withdraw(double money)=0;
    virtual void getBalance()=0;
};

class RealBankAccount: public BankAccount{
    double balance;
public:
    RealBankAccount(double balance){ 
        this->balance=balance;
    }
    void Withdraw(double money) override{
        if(balance<money){
            cout<<"inufficient balance"<<endl;
            return;
        }
        balance-=money;
        cout<<"Withdrawn"<<" remaining balance:"<<balance<<endl;
    }
    void getBalance(){
        cout<<"Remaining balance: "<<balance<<endl;
    }
};

class BankAccountProxy: public BankAccount{
    BankAccount* bankAccount;
    bool authorized;
public:
    BankAccountProxy(BankAccount* bankAccount,bool auth){
        this->bankAccount=bankAccount;
        authorized=auth;
    }
    void Withdraw(double money) override{
        if(!authorized){
            cout<<"user not authorized"<<endl;
            return;
        }
        bankAccount->Withdraw(money);
    }
    void getBalance(){
        bankAccount->getBalance();
    }
};

int main(){
    BankAccount* bankAccount=new RealBankAccount(200);
    BankAccount* operateOnBank=new BankAccountProxy(bankAccount,true);
    operateOnBank->Withdraw(100);
    operateOnBank->getBalance();
}