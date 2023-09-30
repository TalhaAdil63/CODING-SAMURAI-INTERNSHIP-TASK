#include <iostream>
#include <vector>
using namespace std;

// Define a structure to represent book information
struct Book
{
    string title;
    string author;
    string ISBN;
    bool available;
};

// Create a vector to store the library's collection of books
vector<Book> libraryCatalog;

// Function to display the main menu
void displayMenu()
{
    cout << endl;

    cout << "Library Management System Menu: " << endl;
    cout << "1) Add a Book" << endl;
    cout << "2) Remove a Book" << endl;
    cout << "3) Check Book Availability" << endl;
    cout << "4) Display Library Catalog" << endl;
    cout << "5) Exit" << endl;
}

// Function to add a new book to the library catalog
void addBook()
{
    Book newBook;

    cout << endl;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);

    cout << "Enter author: ";
    getline(cin, newBook.author);

    cout << "Enter ISBN: ";
    cin >> newBook.ISBN;

    cout << endl;

    newBook.available = true;
    libraryCatalog.push_back(newBook);

    cout << "Book added successfully!" << endl;
}

// Function to remove a book from the catalog
void removeBook()
{
    cout << endl;

    string searchTitle;
    cout << "Enter book title to remove: ";
    cin.ignore();
    getline(cin, searchTitle);

    for(int i = 0; i < libraryCatalog.size(); i++)
    {
        if(libraryCatalog[i].title == searchTitle)
        {
            libraryCatalog.erase(libraryCatalog.begin() + i);

            cout << endl;

            cout << "Book removed successfully!" << endl;
            return;
        }
    }
    cout << "Book not found in the catalog." << endl;
}

// Function to check the availability of a book by title
void checkAvailability()
{
    string searchTitle;
    cout << "Enter book title to check availability: ";
    cin.ignore();
    getline(cin, searchTitle);

    for(const Book& book : libraryCatalog)
    {
        if(book.title == searchTitle)
        {
            if(book.available)
            {
                cout << "The book is available." << endl;
            }
            else
            {
                cout << "the book is currently checked out." << endl;
            }
            return;
        }
    }
    cout << "Book not found in the catalog." << endl;
}

// Function to display the library catalog
void displayCatalog()
{
    cout << "Library Catalog: " << endl;

    cout << endl;

    for(const Book& book : libraryCatalog)
    {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.ISBN << endl;
        cout << "Availability: " << (book.available ? "Available" : "Checked Out") << endl;
        cout << "---------------------------------------" << endl;
    }
}

int main(void)
{
    while(true)
    {
        displayMenu();

        int choice;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            checkAvailability();
            break;
        case 4:
            displayCatalog();
            break;
        case 5:
            cout << "Thanks for using the Library Management System. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please select a valid option from the menu." << endl;
            break;
        }
    }
}
