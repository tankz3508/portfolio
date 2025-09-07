# Todo List

A simple console-based, file I/O-compatible todo list implemented in C++.
Focuses on practicing OOP with classes, setters/getters, and file operations.

## How to Use

Example usage:

```cpp
#include "../include/todo.h"

int main() {
    //           title    description   iscompleted?
    Todo todo1{ "title", "description", false };

    todo1.setName("New title");
    todo1.setDescription("New description");
    todo1.setCompleted(true);

    todo1.write("output.txt");    // save to file
    todo1.load("output.txt");     // load from file
    todo1.clear("output.txt");    // Optional: clear file

    return 0;
```

> **:warning: Note**
> This is a hobby project to practice classes, file I/O, and basic OOP in C++.
