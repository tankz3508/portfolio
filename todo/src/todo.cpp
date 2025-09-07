#include "../include/todo.h"
#include <iostream>
#include <fstream>

Todo::Todo(const std::string& name, const std::string& description, bool completed) 
    : m_name{name}, m_description{description}, m_completed{completed} {}

void Todo::setName(const std::string& name) { m_name = name; }
void Todo::setDescription(const std::string& description) { m_description = description; }
void Todo::setCompleted(bool completed) { m_completed = completed; }

std::string Todo::getName() { return m_name; }
std::string Todo::getDescription() { return m_description; }
bool Todo::getCompleted() const { return m_completed; }

void Todo::write(const std::string& path) const {
    std::ofstream file(path, std::ios::out | std::ios::app);

    std::string completed_str = m_completed ? "Completed" : "Uncompleted";

    file << m_name << '\n';
    file << m_description << '\n';
    file << completed_str << '\n';

    file.close();
}

void Todo::load(const std::string& path) {
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }

    file.close();
}

void Todo::clear(const std::string& path) {
    std::ofstream file(path, std::ios::out | std::ios::trunc);
    file.close();
}
