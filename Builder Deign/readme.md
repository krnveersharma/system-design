# 🏗️ Builder Design Pattern in C++

This project demonstrates the **Builder Design Pattern** using a `Computer` object. The Builder pattern allows step-by-step construction of complex objects, separating construction logic from the final representation.

---

## 📂 Files

- `main.cpp` — Contains all class implementations and the `main()` function demonstrating the pattern.

---

## 💡 What is the Builder Pattern?

The **Builder Pattern** is a creational design pattern used to construct a complex object step-by-step. It lets you build different types and representations of an object using the same construction process.

---

## ✅ Components

| Component              | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| `Computer`             | The complex object we want to build (product).                             |
| `ComputerBuilder`      | Abstract builder interface defining all the steps to build a computer.     |
| `DellComputerBuilder`  | Concrete builder class for Dell computers.                                 |
| `MacComputerBuilder`   | Concrete builder class for Mac computers.                                  |
| `Director`             | Constructs the product using a given builder.                              |
| `main()`               | Client code that uses the pattern to build and display computers.          |

---

## 🧱 Step-by-Step Explanation

1. **Define the Product class (`Computer`)**  
   Has private fields (`cpu`, `memory`, `ram`) and setters to assign values.

2. **Create an Abstract Builder (`ComputerBuilder`)**  
   Specifies all steps required to build a computer (CPU, Memory, RAM).

3. **Implement Concrete Builders (`DellComputerBuilder`, `MacComputerBuilder`)**  
   Provide specific configurations for different types of computers.

4. **Define a Director class**  
   Calls builder methods in a specific sequence to assemble the computer.

5. **Use in `main()`**  
   The client creates builders and passes them to the director to build the final object.

---

