#include <iostream>
#include <string>
using namespace std;

//
// 🔶 Abstract Prototype Class
// Why? We define a base class with a virtual clone() function
// so we can create copies of objects **without knowing their exact type** at runtime.
//
class GameCharacter {
public:
    string name;
    int health;
    int power;

    virtual ~GameCharacter() {}

    // ❗ Pure virtual clone function — this is the key part of the Prototype pattern.
    // Why? This lets us copy a character even if we only have a pointer to the base class.
    virtual GameCharacter* clone() const = 0;

    virtual void display() const {
        cout << "Name: " << name << ", Health: " << health << ", Power: " << power << endl;
    }
};

//
// 🛡️ Concrete Prototype: Warrior
// Why? This is a concrete class that overrides clone() to copy itself.
//
class Warrior : public GameCharacter {
public:
    Warrior() {
        name = "Warrior";
        health = 150;
        power = 30;
    }

    // ✔️ Copy constructor
    // Why? Used internally by clone() to duplicate an object’s exact state.
    Warrior(const Warrior& other) {
        name = other.name;
        health = other.health;
        power = other.power;
    }

    // ✅ clone() returns a new Warrior copy
    // Why? So we can create exact duplicates at runtime without calling `new Warrior()` directly.
    GameCharacter* clone() const override {
        return new Warrior(*this); // using the copy constructor
    }
};

//
// 🔮 Concrete Prototype: Mage
//
class Mage : public GameCharacter {
public:
    Mage() {
        name = "Mage";
        health = 80;
        power = 100;
    }

    Mage(const Mage& other) {
        name = other.name;
        health = other.health;
        power = other.power;
    }

    GameCharacter* clone() const override {
        return new Mage(*this);
    }
};

//
// 🧪 Usage
//
int main() {
    // 🔧 Step 1: Create prototypes
    // These are like "blueprints" for each character type.
    GameCharacter* warriorPrototype = new Warrior();
    GameCharacter* magePrototype = new Mage();

    // 🔁 Step 2: Clone characters at runtime
    // Why clone()? Imagine a game engine where you spawn many characters during gameplay.
    // Instead of writing complex initialization each time, we just clone the prototype.
    //
    // Advantage: Decouples character creation logic from specific subclasses.
    GameCharacter* player1 = warriorPrototype->clone();
    player1->name = "Player1 the Brave";  // Customize after cloning

    GameCharacter* player2 = magePrototype->clone();
    player2->name = "Player2 the Wise";

    // 🖨️ Step 3: Use the cloned objects
    player1->display();  // Output: Player1 the Brave, Health: 150, Power: 30
    player2->display();  // Output: Player2 the Wise, Health: 80, Power: 100

    //
    // 🚫 What if we didn’t use clone()?
    //
    // We'd have to use if-else or switch-case to manually create characters:
    // if (type == "warrior") { new Warrior(); } else if ...
    // ❌ This breaks Open/Closed Principle and makes code hard to maintain and extend.

    //
    // 🧹 Step 4: Clean up memory
    delete warriorPrototype;
    delete magePrototype;
    delete player1;
    delete player2;

    return 0;
}
