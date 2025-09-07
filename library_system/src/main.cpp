#include <iostream>
#include <vector>
#include <numeric>

class Book {
private:
    int m_id;
    std::string m_title;
    std::string m_author;
public:
    Book(int id, const std::string& title, const std::string& author) : m_id(id), m_title(title), m_author(author) {}

    int get_id() const { return m_id; }
    const std::string& get_title() const { return m_title; }
    const std::string& get_author() const { return m_author; }

    void print() const {
        std::cout << m_title << " by " << m_author << " (" << m_id << ")\n";
    }
};

int main() {
    std::vector<Book> books;

    while (true) {
        std::cout << "1. Add book\n";
        std::cout << "2. List all books\n";
        std::cout << "3. Search by ID/title/author\n";
        std::cout << "4. Remove a book\n";
        std::cout << "5. Exit\n";
        std::cout << "> ";

        int input;
        std::cin >> input;

        switch (input) {
            case 1: {
                int book_id;
                std::string book_title;
                std::string book_author;

                std::cout << "Enter book id: ";
                std::cin >> book_id;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter book title: ";
                std::getline(std::cin, book_title);

                std::cout << "Enter the author: ";
                std::getline(std::cin, book_author);

                books.push_back({book_id, book_title, book_author});

                std::cout << "Added book successfully.\n";
                break;
            }
            case 2: {
                for (int i = 0; i < books.size(); i++) {
                    std::cout << i + 1 << ". ";
                    books[i].print();
                }

                break;
            }
            case 3: {
                std::cout << "Enter book title or id: ";
                std::string book_title;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::getline(std::cin, book_title);

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].get_title() == book_title) {
                        std::cout << i + 1 << ". ";
                        books[i].print();
                    } else if (books[i].get_author() == book_title) {
                        std::cout << i + 1 << ". ";
                        books[i].print();
                    } else {
                        try {
                            if (books[i].get_id() == std::stoi(book_title)) {
                                std::cout << i + 1 << ". ";
                                books[i].print();
                            }
                        } catch (...) {}
                    }
                }

                break;
            }
            case 4: {
                std::cout << "Enter book title: ";
                std::string book_title;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::getline(std::cin, book_title);

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].get_title() == book_title) {
                        books.erase(books.begin() + i);
                    }
                }
                std::cout << "Successfully removed book.\n";

                break;
            }
            case 5: {
                std::cout << "Exiting...";
                std::exit(0);
            }
        }
    }
}
