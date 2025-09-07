#pragma once

#include <string>

class Todo {
private:
    std::string m_name;
    std::string m_description;
    bool m_completed;
public:
    Todo(const std::string& name, const std::string& description, bool completed);

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setCompleted(bool completed);

    std::string getName();
    std::string getDescription();
    bool getCompleted() const;

    void write(const std::string& path) const;
    void load(const std::string& path);
    void clear(const std::string& path);
};
