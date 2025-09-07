# Todo

A simple I/O compatible Todo-list implemented in C++

It's fast, easy to use and works good.

# How to use?

```cpp
#include "../include/todo.h"

int main() {
    // DUMMY SKELETON CODE
    Todo todo1 { "Title", "Description", false };

    todo1.setName("New Title");
    todo1.setDescription("New Description");
    todo1.setCompleted(true);

    todo1.write("output.txt");
    todo1.load("output.txt");

    // todo1.clear("output.txt");

    return 0;
}
```

---
### :warning: This is a hobby project to practice the use of Classes and generally OOP in C++. :warning:
