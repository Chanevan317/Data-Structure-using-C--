#include <iostream>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;
    Node(int coef, int exp) {
        coefficient = coef;
        exponent = exp;
        next = nullptr;
    }
};

class Polynomial {
    private:
        Node* head;

    public:
        Polynomial() {
            head = nullptr;
        }

        // Insert a term into the polynomial in sorted order
        void insertTerm(int coef, int exp) {
            if (coef == 0) return;

            Node* newNode = new Node(coef, exp);

            // If the list is empty or the new node should be the new head
            if (head == nullptr || head->exponent < exp) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;

                // Traverse to find the correct position
                while (current->next != nullptr && current->next->exponent >= exp) {
                    if (current->next->exponent == exp) {
                        // If the term already exists, update the coefficient
                        current->next->coefficient += coef;
                        delete newNode; // The newNode is not needed anymore
                        return;
                    }
                    current = current->next;
                }

                // Insert the new node in the correct position
                newNode->next = current->next;
                current->next = newNode;
            }
        }

        // Function to display the polynomial
        void display() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->coefficient << "x^" << temp->exponent;
                temp = temp->next;
                if (temp != nullptr && temp->coefficient > 0) {
                    cout << " + ";
                }
            }
            cout << endl;
        }

        // Function to add a new term to the polynomial at runtime
        void addTerm(int coef, int exp) {
            insertTerm(coef, exp);
        }
};

int main() {
    Polynomial poly;

    // Existing terms in the polynomial
    poly.insertTerm(3, 4);
    poly.insertTerm(2, 3);
    poly.insertTerm(5, 2);

    cout << "Initial Polynomial: ";
    poly.display();

    // Adding a new term at runtime
    int coef, exp;
    cout << "Enter the coefficient and exponent of the new term: ";
    cin >> coef >> exp;
    poly.addTerm(coef, exp);

    cout << "Updated Polynomial: ";
    poly.display();

    return 0;
}
