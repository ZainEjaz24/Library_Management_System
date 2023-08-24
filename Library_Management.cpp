#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year)
        : title(title), author(author), year(year), available(true) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    bool isAvailable() const {
        return available;
    }

    void borrow() {
        available = false;
    }

    void returnBook() {
        available = true;
    }

private:
    std::string title;
    std::string author;
    int year;
    bool available;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const Book& book : books) {
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Year: " << book.getYear() << std::endl;
            std::cout << "Status: " << (book.isAvailable() ? "Available" : "Borrowed") << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    void borrowBook(const std::string& title) {
        for (Book& book : books) {
            if (book.getTitle() == title && book.isAvailable()) {
                book.borrow();
                std::cout << "You have successfully borrowed '" << title << "'." << std::endl;
                return;
            }
        }
        std::cout << "Book '" << title << "' is not available for borrowing." << std::endl;
    }

    void returnBook(const std::string& title) {
        for (Book& book : books) {
            if (book.getTitle() == title && !book.isAvailable()) {
                book.returnBook();
                std::cout << "You have successfully returned '" << title << "'." << std::endl;
                return;
            }
        }
        std::cout << "Invalid book title or the book was not borrowed from this library." << std::endl;
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    while (true) {
        std::cout << "Library Management System" << std::endl;
        std::cout << "1. Display Books" << std::endl;
        std::cout << "2. Borrow Book" << std::endl;
        std::cout << "3. Return Book" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2: {
                std::string title;
                std::cout << "Enter the title of the book you want to borrow: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.borrowBook(title);
                break;
            }
            case 3: {
                std::string title;
                std::cout << "Enter the title of the book you want to return: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.returnBook(title);
                break;
            }
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
