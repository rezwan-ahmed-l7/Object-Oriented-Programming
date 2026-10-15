#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string normalize(const string &value)
{
    string result = value;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char ch) { return static_cast<char>(tolower(ch)); });
    return result;
}

class Book
{
private:
    string title;
    string author;
    bool checkedOut;

public:
    Book(const string &bookTitle, const string &bookAuthor)
        : title(bookTitle), author(bookAuthor), checkedOut(false) {}

    const string &getTitle() const { return title; }

    bool checkout()
    {
        if (checkedOut)
            return false;
        checkedOut = true;
        return true;
    }

    bool returnBook()
    {
        if (!checkedOut)
            return false;
        checkedOut = false;
        return true;
    }

    void displayStatus() const
    {
        cout << "Title: " << title << " | Author: " << author
             << " | Status: " << (checkedOut ? "Checked out" : "Available") << '\n';
    }
};

class Library
{
private:
    vector<Book> books;

public:
    void addBook(const string &title, const string &author)
    {
        if (findBookIndex(title) != -1)
        {
            cout << "A book with that title already exists: " << title << '\n';
            return;
        }
        books.emplace_back(title, author);
    }

    int findBookIndex(const string &title) const
    {
        for (size_t i = 0; i < books.size(); ++i)
            if (normalize(books[i].getTitle()) == normalize(title))
                return static_cast<int>(i);
        return -1;
    }

    void checkoutBook(const string &title)
    {
        int index = findBookIndex(title);
        if (index == -1)
            cout << "Book not found: " << title << '\n';
        else if (!books[index].checkout())
            cout << "Book is already checked out: " << title << '\n';
        else
            cout << "Checked out: " << title << '\n';
    }

    void returnBook(const string &title)
    {
        int index = findBookIndex(title);
        if (index == -1)
            cout << "Book not found: " << title << '\n';
        else if (!books[index].returnBook())
            cout << "Book was not checked out: " << title << '\n';
        else
            cout << "Returned: " << title << '\n';
    }

    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "The library has no books.\n";
            return;
        }
        for (const Book &book : books)
            book.displayStatus();
    }
};

int main()
{
    Library library;
    library.addBook("Physics", "Halliday and Resnick");
    library.addBook("Chemistry", "Raymond Chang");
    library.addBook("Bangla", "Humayun Azad");
    library.addBook("English", "William Shakespeare");
    library.addBook("Math", "K. A. Stroud");

    cout << "Initial library catalogue:\n";
    library.displayAllBooks();

    cout << "\nCheckout and return test:\n";
    library.checkoutBook("Physics");
    library.checkoutBook("physics");
    library.returnBook("Physics");
    library.returnBook("Physics");

    cout << "\nFinal library catalogue:\n";
    library.displayAllBooks();
    return 0;
}
