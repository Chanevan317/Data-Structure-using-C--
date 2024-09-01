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

        // Helper function to insert a term into the polynomial in sorted order
        void insertTerm(int coef, int exp) {
            if (coef == 0) return;

            Node* newNode = new Node(coef, exp);
            if (head == nullptr || head->exponent < exp) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr && current->next->exponent >= exp) {
                    if (current->next->exponent == exp) {
                        current->next->coefficient += coef;
                        delete newNode;
                        return;
                    }
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }

    public:
        Polynomial() {
            head = nullptr;
        }

        // Insert a term into the polynomial
        void insert(int coef, int exp) {
            insertTerm(coef, exp);
        }

        // traverse the polynomial
        void traverse() {
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

        // Add two polynomials
        Polynomial add(Polynomial& other) {
            Polynomial result;
            Node* p1 = head;
            Node* p2 = other.head;

            while (p1 != nullptr && p2 != nullptr) {
                if (p1->exponent > p2->exponent) {
                    result.insert(p1->coefficient, p1->exponent);
                    p1 = p1->next;
                } else if (p1->exponent < p2->exponent) {
                    result.insert(p2->coefficient, p2->exponent);
                    p2 = p2->next;
                } else {
                    result.insert(p1->coefficient + p2->coefficient, p1->exponent);
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }

            while (p1 != nullptr) {
                result.insert(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }

            while (p2 != nullptr) {
                result.insert(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }

            return result;
        }

        // Subtract two polynomials
        Polynomial subtract(Polynomial& other) {
            Polynomial result;
            Node* p1 = head;
            Node* p2 = other.head;

            while (p1 != nullptr && p2 != nullptr) {
                if (p1->exponent > p2->exponent) {
                    result.insert(p1->coefficient, p1->exponent);
                    p1 = p1->next;
                } else if (p1->exponent < p2->exponent) {
                    result.insert(-p2->coefficient, p2->exponent);
                    p2 = p2->next;
                } else {
                    result.insert(p1->coefficient - p2->coefficient, p1->exponent);
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }

            while (p1 != nullptr) {
                result.insert(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }

            while (p2 != nullptr) {
                result.insert(-p2->coefficient, p2->exponent);
                p2 = p2->next;
            }

            return result;
        }

        // Multiply two polynomials
        Polynomial multiply(Polynomial& other) {
            Polynomial result;
            Node* p1 = head;

            while (p1 != nullptr) {
                Node* p2 = other.head;
                while (p2 != nullptr) {
                    result.insert(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
                    p2 = p2->next;
                }
                p1 = p1->next;
            }

            return result;
        }

        // Divide two polynomials (placeholder function)
        Polynomial divide(Polynomial& other) {
            // Placeholder: Implement polynomial division if needed
            Polynomial result;
            cout << "Division operation not implemented." << endl;
            return result;
        }

        // Perform operations based on user input
        void performOperation(int choice, Polynomial& other) {
            Polynomial result;
            switch (choice) {
                case 0:
                    result = add(other);
                    cout << "Addition Result : ";
                    break;
                case 1:
                    result = subtract(other);
                    cout << "Subtraction Result : ";
                    break;
                case 2:
                    result = divide(other);
                    cout << "Division Result : ";
                    break;
                case 3:
                    result = multiply(other);
                    cout << "Multiplication Result : ";
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    return;
            }
            result.traverse();
        }
};

int main() {
    Polynomial p1, p2;

    // Polynomial 1: 3x^4 + 2x^3 + 5x^2
    p1.insert(3, 4);
    p1.insert(2, 3);
    p1.insert(5, 2);
    cout << "Polynomial 1 : ";
    p1.traverse();

    // Polynomial 2: 4x^3 + 2x^2 + 7
    p2.insert(4, 3);
    p2.insert(2, 2);
    p2.insert(7, 0);
    cout << "Polynomial 2 : ";
    p2.traverse();

    // User choice for operation
    int choice;
    cout << "Enter operation (0: Addition, 1: Subtraction, 2: Division, 3: Multiplication) : ";
    cin >> choice;

    p1.performOperation(choice, p2);

    return 0;
}

    