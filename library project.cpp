#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int year) {
        books.push_back(Book(title, author, year));
        cout << "Book added successfully!" << endl;
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        for (const auto& ;book ; books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
        }
    }

    void searchBook(string title) {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found!" << endl;
                cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void removeBook(string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Remove Book by Title\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            library.addBook(title, author, year);
            break;
        case 2:
            library.viewBooks();
            break;
        case 3:
            cout << "Enter title: ";
            getline(cin, title);
            library.searchBook(title);
            break;
        case 4:
            cout << "Enter title: ";
            getline(cin, title);
            library.removeBook(title);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

