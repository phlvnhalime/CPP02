# 📦 CPP02 – Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

Welcome to my repository for **CPP02**, the third module of the C++ curriculum at **42 School**.  
This project introduces **Orthodox Canonical Form**, **operator overloading**, **ad-hoc polymorphism**, and **fixed-point number representation** using the **C++98 standard**.

---

## 🔍 Overview

This module covers essential C++ design patterns and advanced OOP concepts:
- **Orthodox Canonical Form** (The Big Four)
- **Fixed-Point Number Systems** for precise calculations
- **Operator Overloading** for natural syntax
- **Ad-hoc Polymorphism** through function overloading
- **Copy Semantics** and proper resource management
- **Stream Output Operators** for custom types

The goal is to understand proper class design patterns and create robust, reusable classes that behave like built-in types.

---

## 🛠️ Compilation Rules

- **Compiler:** `c++`
- **Flags:** `-Wall -Wextra -Werror -std=c++98`
- ❌ No external libraries  
- ❌ No C++11 (or later) features  
- ❌ STL usage is **forbidden** until Module 08
- ❌ Forbidden functions: `*printf()`, `*alloc()`, `free()`
- ✅ Allowed: `roundf()` from `<cmath>`

---

## 📁 Project Structure

```plaintext
CPP02/
├── ex00/
├── ex01/
├── ex02/
└── ex03/ (Optional)
```

Each folder contains a separate exercise building towards a complete Fixed-point number class with full operator support.

---

## 🏛️ Orthodox Canonical Form

**From CPP02 onwards, ALL classes must implement the "Big Four":**

```cpp
class MyClass {
public:
    MyClass();                          // Default constructor
    MyClass(const MyClass& other);      // Copy constructor  
    MyClass& operator=(const MyClass& other); // Copy assignment operator
    ~MyClass();                         // Destructor
};
```

This ensures proper **copy semantics** and **resource management**.

---

## 📘 Exercises Summary

### 🔢 ex00 – My First Class in Orthodox Canonical Form

**Goal:**  
Create a basic `Fixed` class representing **fixed-point numbers** with Orthodox Canonical Form.

**Key Components:**
- Private integer to store fixed-point value
- Static constant for fractional bits (8)
- Complete Orthodox Canonical Form implementation
- Basic getter/setter methods

**What I Learned:**
- **Fixed-point arithmetic** fundamentals
- **Orthodox Canonical Form** pattern implementation
- **Static const member** variables
- **Constructor/destructor lifecycle** tracking
- Difference between **floating-point** and **fixed-point** representation

**Expected Output:**
```
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
0
Destructor called
```

### 🔧 ex01 – Towards a more useful fixed-point number class

**Goal:**  
Extend the Fixed class with **constructors**, **conversion functions**, and **stream output**.

**New Features:**
- `Fixed(const int value)` - Integer constructor
- `Fixed(const float value)` - Float constructor  
- `float toFloat() const` - Convert to float
- `int toInt() const` - Convert to integer
- `operator<<` overload for stream output

**What I Learned:**
- **Type conversion** between different number systems
- **Constructor overloading** for different input types
- **Stream insertion operator** (`<<`) overloading
- **Const correctness** in member functions
- **Fixed-point arithmetic** implementation details

**Usage Example:**
```cpp
Fixed a;                    // Default: 0
Fixed b(10);               // From integer
Fixed c(42.42f);          // From float
Fixed d(b);               // Copy constructor

std::cout << "a is " << a << std::endl; // Uses operator<<
```

### ⚙️ ex02 – Now we're talking

**Goal:**  
Implement **complete operator overloading** to make Fixed behave like built-in numeric types.

**Operators Implemented:**

**Comparison Operators:**
- `>`, `<`, `>=`, `<=`, `==`, `!=`

**Arithmetic Operators:**
- `+`, `-`, `*`, `/`

**Increment/Decrement:**
- `++a` (pre-increment), `a++` (post-increment)
- `--a` (pre-decrement), `a--` (post-decrement)

**Static Member Functions:**
- `Fixed::min(Fixed& a, Fixed& b)` - Returns smaller value
- `Fixed::min(const Fixed& a, const Fixed& b)` - Const version
- `Fixed::max(Fixed& a, Fixed& b)` - Returns larger value  
- `Fixed::max(const Fixed& a, const Fixed& b)` - Const version

**What I Learned:**
- **Operator overloading** syntax and best practices
- **Pre vs post-increment/decrement** implementation
- **Static member functions** for utility operations
- **Function overloading** based on const-ness
- **Ad-hoc polymorphism** through operator overloading
- **Return value optimization** considerations

**Usage Example:**
```cpp
Fixed a;
Fixed b(Fixed(5.05f) * Fixed(2));

std::cout << ++a << std::endl;        // Pre-increment
std::cout << a++ << std::endl;        // Post-increment  
std::cout << Fixed::max(a, b) << std::endl; // Static function
```

### 🎯 ex03 – BSP (Binary Space Partitioning) [Optional]

**Goal:**  
Apply the Fixed class to solve a geometric problem: **point-in-triangle detection**.

**Implementation:**
- `Point` class with Fixed coordinates
- `bool bsp(Point a, Point b, Point c, Point point)` function
- **Binary Space Partitioning** algorithm

**Point Class Features:**
- `Fixed const x, y` - Immutable coordinates
- Orthodox Canonical Form compliance
- Floating-point constructor for initialization

**What I Learned:**
- **Practical application** of fixed-point arithmetic
- **Geometric algorithms** implementation
- **Const member variables** and initialization
- **Real-world usage** of custom numeric types
- **Binary Space Partitioning** concepts

---

## 💡 Key Concepts Mastered

### 🏗️ **Orthodox Canonical Form**
The foundation of proper C++ class design - ensuring safe copy semantics.

### 🔢 **Fixed-Point Arithmetic**
Alternative to floating-point for applications requiring:
- **Deterministic results**
- **Better precision control**  
- **Performance in embedded systems**
- **Avoiding floating-point rounding errors**

### ⚡ **Operator Overloading**
Making custom classes behave like built-in types:
- **Natural syntax** (`a + b` instead of `a.add(b)`)
- **Intuitive user experience**
- **Integration with existing code**

### 🔄 **Ad-hoc Polymorphism**
Function overloading based on parameter types and const-ness.

---

## 🎯 Design Patterns Applied

### **RAII (Resource Acquisition Is Initialization)**
```cpp
Fixed a(42.42f);  // Resource acquired in constructor
// Resource automatically released in destructor
```

### **Value Semantics**
```cpp
Fixed a(10);
Fixed b = a;      // Deep copy, not sharing
b = a + Fixed(5); // Operations create new values
```

### **Operator Consistency**
```cpp
// All related operators work together
if (a < b) { /* ... */ }        // Comparison
Fixed c = a + b;                // Arithmetic
std::cout << ++a << std::endl;  // Increment + Stream
```

---

## 🚨 Common Implementation Challenges

### **Pre vs Post-Increment**
```cpp
// Pre-increment: increment then return
Fixed& operator++() {
    this->value++;
    return *this;
}

// Post-increment: return copy, then increment
Fixed operator++(int) {
    Fixed old = *this;
    ++(*this);
    return old;
}
```

### **Copy Assignment Self-Check**
```cpp
Fixed& operator=(const Fixed& other) {
    if (this != &other) {  // Self-assignment check
        this->value = other.value;
    }
    return *this;
}
```

### **Const Correctness**
```cpp
float toFloat() const;  // Doesn't modify object
Fixed& operator++();    // Modifies object (no const)
```

---

## 🔬 Fixed-Point Implementation Details

### **Representation**
- **Integer storage** with implicit fractional bits
- **8 fractional bits** = 1/256 precision
- **Value = raw_value / (2^fractional_bits)**

### **Conversion Formulas**
```cpp
// Float to Fixed
raw_value = roundf(float_value * (1 << fractional_bits));

// Fixed to Float  
float_value = (float)raw_value / (1 << fractional_bits);
```

---

## 📣 Final Notes

This module was crucial for understanding **modern C++ class design principles**. The Orthodox Canonical Form becomes second nature, and operator overloading opens up elegant API design possibilities.

**Key Takeaways:**
- **Orthodox Canonical Form is mandatory** for robust classes
- **Fixed-point arithmetic** offers advantages over floating-point in many scenarios
- **Operator overloading** enables natural, intuitive syntax
- **Proper copy semantics** prevent subtle bugs and memory issues
- **Static member functions** provide clean utility interfaces

💬 *"You think you know integers and floating-point numbers. How cute."* - Understanding alternative number representations expands programming possibilities!

The Fixed class demonstrates how C++ enables creating **custom types that feel built-in** while maintaining **performance and safety**. Perfect foundation for advanced OOP concepts! 🚀

---

**Author:** Halime Pehlivan.  
**School:** 42 Heilbronn
