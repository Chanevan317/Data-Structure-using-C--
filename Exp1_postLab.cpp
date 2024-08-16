#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Class representing a book
class Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool status; // true for available, false for issued

public:
    Book(const std::string &t, const std::string &a, const std::string &i) 
        : title(t), author(a), ISBN(i), status(true) {}

    // Getters and setters
    bool getStatus() const { return status; }
    void setStatus(bool s) { status = s; }
    std::string getISBN() const { return ISBN; }
};

// Class representing a library member
class Member {
    std::string memberID;
    std::string name;
    std::vector<Book*> borrowedBooks;

public:
    Member(const std::string &id, const std::string &n) 
        : memberID(id), name(n) {}

    // Add and remove books from borrowed list
    void borrowBook(Book &b) { borrowedBooks.push_back(&b); }
    void returnBook(Book &b) {
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), &b), borrowedBooks.end());
    }
    std::string getID() const { return memberID; }
};

// Class representing the library
class Library {
    std::vector<Book> books;
    std::vector<Member> members;

public:
    // Add new book and member
    void addBook(const Book &b) { books.push_back(b); }
    void registerMember(const Member &m) { members.push_back(m); }

    // Find book and member by ID
    Book* findBookByISBN(const std::string &isbn) {
        for (auto &b : books) {
            if (b.getISBN() == isbn) return &b;
        }
        return nullptr;
    }
    Member* findMemberByID(const std::string &id) {
        for (auto &m : members) {
            if (m.getID() == id) return &m;
        }
        return nullptr;
    }

    // Issue and return book
    void issueBook(const std::string &isbn, const std::string &memberID) {
        Book* book = findBookByISBN(isbn);
        Member* member = findMemberByID(memberID);

        if (book && member && book->getStatus()) {
            book->setStatus(false);
            member->borrowBook(*book);
            std::cout << "Book issued successfully.\n";
        } else {
            std::cout << "Book cannot be issued.\n";
        }
    }

    void returnBook(const std::string &isbn, const std::string &memberID) {
        Book* book = findBookByISBN(isbn);
        Member* member = findMemberByID(memberID);

        if (book && member && !book->getStatus()) {
            book->setStatus(true);
            member->returnBook(*book);
            std::cout << "Book returned successfully.\n";
        } else {
            std::cout << "Book cannot be returned.\n";
        }
    }
};

int main() {
    Library lib;
    
    // Creating books and members
    Book b1("Book Title 1", "Author 1", "1234");
    Book b2("Book Title 2", "Author 2", "5678");
    Member m1("001", "Member 1");
    
    lib.addBook(b1);
    lib.addBook(b2);
    lib.registerMember(m1);
    
    // Issuing and returning books
    lib.issueBook("1234", "001");
    lib.returnBook("1234", "001");

    return 0;
}

