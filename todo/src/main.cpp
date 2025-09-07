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
