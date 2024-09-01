#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Exception Classes
class BookNotFoundException : public runtime_error 
{
public:
    BookNotFoundException() : runtime_error("Book not found.") {}
};

class MemberNotFoundException : public runtime_error 
{
public:
    MemberNotFoundException() : runtime_error("Member not found.") {}
};

class BookNotAvailableException : public runtime_error 
{
public:
    BookNotAvailableException() : runtime_error("Book not available.") {}
};


// Base User Class
class User 
{
    protected:
        int userID;
        string name;
    public:
        User(int id, const string& nm) : userID(id), name(nm) {}

        int getUserID() const { return userID; }
};

// Derived Member Class
class Member : public User 
{
    private:
        vector<string> borrowedBooks;
    public:
        Member(int id, const string& nm) : User(id, nm) {}

        void addBook(const string& book) 
        {
            borrowedBooks.push_back(book);
        }

        void removeBook(const string& book) 
        {
            for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
                if (*it == book) {
                    borrowedBooks.erase(it);
                    return;
                }
            }
        }

        vector<string> getBorrowedBooks() const 
        {
            return borrowedBooks;
        }
};

// Derived Librarian Class
class Librarian : public User 
{
    public:
        Librarian(int id, const string& nm) : User(id, nm) {}
};

// Book Class
class Book 
{
    private:
        string title;
        string ISBN;
        bool isAvailable;
    public:
        Book(const string& ttl, const string& isbn, bool available)
            : title(ttl), ISBN(isbn), isAvailable(available) {}

        string getTitle() const { return title; }
        string getISBN() const { return ISBN; }
        bool getStatus() const { return isAvailable; }

        void setStatus(bool available) { isAvailable = available; }
};

// Library Class
class Library 
{
    private:
        vector<Book> books;
        vector<Member> members;

        Book* findBookByISBN(const string& isbn) 
        {
            for (auto& book : books) 
            {
                if (book.getISBN() == isbn) 
                {
                    return &book;
                }
            }
            throw BookNotFoundException();
        }

        Member* findMemberByID(int id) 
        {
            for (auto& member : members) 
            {
                if (member.getUserID() == id) 
                {
                    return &member;
                }
            }
            throw MemberNotFoundException();
        }

    public:
        void addBook(const Book& book) 
        {
            books.push_back(book);
        }

        void registerMember(const Member& member) 
        {
            members.push_back(member);
        }

        void issueBook(const string& isbn, int memberID) 
        {
            Book* book = findBookByISBN(isbn);
            Member* member = findMemberByID(memberID);

            if (!book->getStatus()) 
            {
                throw BookNotAvailableException();
            }

            book->setStatus(false);
            member->addBook(book->getTitle());
        }

        void returnBook(const string& isbn, int memberID) 
        {
            Book* book = findBookByISBN(isbn);
            Member* member = findMemberByID(memberID);

            book->setStatus(true);
            member->removeBook(book->getTitle());
        }
};


int main() 
{
    Library lib;

    lib.addBook(Book("1984", "123456", true));
    lib.addBook(Book("To Kill a Mockingbird", "789101", true));

    lib.registerMember(Member(1, "Alice"));
    lib.registerMember(Member(2, "Bob"));

    try 
    {
        lib.issueBook("123456", 1);
        cout << "Book issued successfully." << endl;

        lib.returnBook("123456", 1);
        cout << "Book returned successfully." << endl;
    } 
    catch (const runtime_error& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
