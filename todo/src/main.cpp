#include <iostream>
#include <fstream>

class Todo {
private:
    std::string m_name;
    std::string m_description;
    bool m_completed;
public:
    Todo(const std::string& name, const std::string& description, bool completed) 
    : m_name{name}, m_description{description}, m_completed{completed} {}

    void setName(const std::string& name) { m_name = name; }
    void setDescription(const std::string& description) { m_description = description; }
    void setCompleted(bool completed) { m_completed = completed; }

    std::string getName() { return m_name; }
    std::string getDescription() { return m_description; }
    bool getCompleted() const { return m_completed; }

    void write(const std::string& path) const {
        std::ofstream file(path, std::ios::out | std::ios::app);

        std::string completed_str = m_completed ? "Completed" : "Uncompleted";

        file << m_name << '\n';
        file << m_description << '\n';
        file << completed_str << '\n';

        file.close();
    }
    
    void load(const std::string& path) {
        std::ifstream file(path);
        std::string line;
    
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
    
        file.close();
    }

    void clear(const std::string& path) {
        std::ofstream file(path, std::ios::out | std::ios::trunc);
        file.close();
    }
};

int main() {
    Todo todo1 { "Title", "Description", false };

    todo1.setName("New Title");
    todo1.setDescription("New Description");
    todo1.setCompleted(true);

    todo1.write("output.txt");
    todo1.load("output.txt");

    // todo1.clear("output.txt");

    return 0;
}
