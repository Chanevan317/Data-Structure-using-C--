#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // Insertion at the beginning
        void insertAtBegin(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        // Insertion at the end
        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (tail == nullptr) {
                head = tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Insertion in between
        void insertInBetween(int data, int pos) {
            if (pos == 0) {
                insertAtBegin(data);
                return;
            }
            
            Node* newNode = new Node(data);
            Node* temp = head;
            
            for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            
            if (temp == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            
            newNode->next = temp->next;
            newNode->prev = temp;
            
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }


        // Deletion from the beginning
        void deleteAtBegin() {
            if (head == nullptr) return;
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }

        // Deletion from the end
        void deleteAtEnd() {
            if (tail == nullptr) return;
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }

        // Delete in between
        void deleteInBetween(int pos) {
            if (pos == 0) {
                deleteAtBegin();
                return;
            }
            
            Node* temp = head;
            
            for (int i = 0; i < pos && temp != nullptr; i++) {
                temp = temp->next;
            }
            
            if (temp == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            
            delete temp;
        }


        // Search for an element
        Node* search(int value) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == value) {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        // Traversal
        void traverse() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    DoublyLinkedList dll;

    // Insert elements
    dll.insertAtBegin(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtBegin(5);
    dll.insertInBetween(15, 2);
    dll.insertInBetween(25, 4);

    // Display list
    cout << "List after insertions : ";
    dll.traverse();

    // Delete elements
    dll.deleteAtBegin();
    dll.deleteAtEnd();
    dll.deleteInBetween(3);

    // Display list
    cout << "List after deletions : ";
    dll.traverse();

    // Search for an element
    int value = 15;
    Node* result = dll.search(value);
    if (result) {
        cout << value << " found in the list." << endl;
    } else {
        cout << value << " not found in the list." << endl;
    }

    return 0;
}
