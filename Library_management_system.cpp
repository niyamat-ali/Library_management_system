#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store book details
struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};

// Function prototypes
void loadBooks(vector<Book> &books);
void saveBooks(const vector<Book> &books);
void addBook(vector<Book> &books);
void searchBook(const vector<Book> &books);
void displayBooks(const vector<Book> &books);

int main() {
    vector<Book> books;
    loadBooks(books); // Load books from file at the start

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                searchBook(books);
                break;
            case 3:
                displayBooks(books);
                break;
            case 4:
                saveBooks(books); // Save books to file before exiting
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to load books from file
void loadBooks(vector<Book> &books) {
    ifstream file("books.txt");
    if (file.is_open()) {
        Book book;
        while (file >> book.bookID) {
            file.ignore(); // Ignore the newline character
            getline(file, book.title);
            getline(file, book.author);
            file >> book.quantity;
            books.push_back(book);
        }
        file.close();
    } else {
        cout << "No existing book inventory found. Starting fresh.\n";
    }
}

// Function to save books to file
void saveBooks(const vector<Book> &books) {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < books.size(); ++i) {
            file << books[i].bookID << "\n";
            file << books[i].title << "\n";
            file << books[i].author << "\n";
            file << books[i].quantity << "\n";
        }
        file.close();
        cout << "Books saved successfully!\n";
    } else {
        cout << "Error saving books to file.\n";
    }
}

// Function to add a new book
void addBook(vector<Book> &books) {
    Book book;
    cout << "Enter Book ID: ";
    cin >> book.bookID;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter Title: ";
    getline(cin, book.title);
    cout << "Enter Author: ";
    getline(cin, book.author);
    cout << "Enter Quantity: ";
    cin >> book.quantity;

    books.push_back(book);
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook(const vector<Book> &books) {
    int choice;
    cout << "Search by:\n1. Book ID\n2. Title\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].bookID == id) {
                cout << "\nBook Found:\n";
                cout << "ID: " << books[i].bookID << "\n";
                cout << "Title: " << books[i].title << "\n";
                cout << "Author: " << books[i].author << "\n";
                cout << "Quantity: " << books[i].quantity << "\n";
                return;
            }
        }
    } else if (choice == 2) {
        string title;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title == title) {
                cout << "\nBook Found:\n";
                cout << "ID: " << books[i].bookID << "\n";
                cout << "Title: " << books[i].title << "\n";
                cout << "Author: " << books[i].author << "\n";
                cout << "Quantity: " << books[i].quantity << "\n";
                return;
            }
        }
    } else {
        cout << "Invalid choice.\n";
        return;
    }
    cout << "Book not found.\n";
}

// Function to display all books
void displayBooks(const vector<Book> &books) {
    if (books.empty()) {
        cout << "No books in the inventory.\n";
        return;
    }

    cout << left << setw(10) << "Book ID" << setw(30) << "Title" << setw(30) << "Author" << setw(10) << "Quantity" << endl;
    cout << string(80, '-') << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << left << setw(10) << books[i].bookID << setw(30) << books[i].title << setw(30) << books[i].author << setw(10) << books[i].quantity << endl;
    }
}

