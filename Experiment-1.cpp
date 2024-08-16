#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 100;

// Simple Book class
class Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    Book(string t = "", string a = "", string i = "")
        : title(t), author(a), ISBN(i), isAvailable(true) {}

    bool isAvailableForLoan() const { return isAvailable; }
    void setAvailability(bool status) { isAvailable = status; }
    string getISBN() const { return ISBN; }
};

// Simple Member class
class Member {
    string memberID;
    string name;
    Book* borrowedBooks[MAX_BOOKS];
    int numBorrowedBooks;

public:
    Member(string id = "", string n = "") : memberID(id), name(n), numBorrowedBooks(0) {}

    void borrowBook(Book &b) {
        if (numBorrowedBooks < MAX_BOOKS) {
            borrowedBooks[numBorrowedBooks++] = &b;
        }
    }

    void returnBook(Book &b) {
        for (int i = 0; i < numBorrowedBooks; ++i) {
            if (borrowedBooks[i] == &b) {
                borrowedBooks[i] = borrowedBooks[--numBorrowedBooks];
                break;
            }
        }
    }

    string getID() const { return memberID; }
};

// Simple Library class
class Library {
    Book books[MAX_BOOKS];
    Member members[MAX_MEMBERS];
    int numBooks;
    int numMembers;

public:
    Library() : numBooks(0), numMembers(0) {}

    void addBook(const Book &b) { books[numBooks++] = b; }
    void addMember(const Member &m) { members[numMembers++] = m; }

    Book* findBook(string isbn) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].getISBN() == isbn) return &books[i];
        }
        return nullptr;
    }

    Member* findMember(string id) {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i].getID() == id) return &members[i];
        }
        return nullptr;
    }

    void issueBook(string isbn, string memberID) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberID);

        if (book && member && book->isAvailableForLoan()) {
            book->setAvailability(false);
            member->borrowBook(*book);
            cout << "Book issued successfully.\n";
        } else {
            cout << "Cannot issue the book.\n";
        }
    }

    void returnBook(string isbn, string memberID) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberID);

        if (book && member && !book->isAvailableForLoan()) {
            book->setAvailability(true);
            member->returnBook(*book);
            cout << "Book returned successfully.\n";
        } else {
            cout << "Cannot return the book.\n";
        }
    }
};

int main() {
    Library lib;

    // Adding books and members
    Book book1("Book Title 1", "Author 1", "1234");
    Book book2("Book Title 2", "Author 2", "5678");
    Member member1("001", "Member 1");

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addMember(member1);

    // Issuing and returning books
    lib.issueBook("1234", "001");
    lib.returnBook("1234", "001");

    return 0;
}

