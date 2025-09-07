# 📂 C++ Portfolio

This repository contains a collection of small projects I built while learning and practicing C++.

Each project lives in its own folder with it's own code and README.

---

## Projects

### [Library System](./library_system)
A basic library management system.
- Add, remove, and list books.
- Runs with a simple menu in `main.cpp`
- Note: currently only stores data in memory.

---

### [Shop System](./shop_system)
A shop and inventory system.
- Shop holds items of different types.
- Player can buy and sell items with a balance.
- Uses enums for item types (e.g., Sword, Dagger, Potion).

---

### [Todo List](./todo)
A small todo-list implementation.
- Add, edit, and mark tasks as complete.
- Can save and load tasks from text files.
- Straightforward OOP design.

---

## Building and Running

Each project has a `main.cpp` file that can be compiled and run on its own. For example:

```bash
g++ -std=c++23 -o main main.cpp
./main
```
