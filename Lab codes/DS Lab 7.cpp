#include <iostream>
using namespace std;

class Stack 
{
    private :
        int* stack;
        int top;
        int capacity;

    public :
        Stack(int cap)
        {
            top = -1;
            capacity = cap;
            stack = new int[cap];
        }

        int size()
        {
            return (top + 1);
        }

        bool isEmpty()
        {
            if(top == -1) return true;
            return false;
        }

        bool isFull()
        {
            if(top == capacity - 1) return true;
            return false;
        }

        int peek()
        {
            if(isEmpty()) 
            {
                cout << "Stack list empty !" << endl;
                return -1;
            }
            return stack[top];
        }

        void push(int val)
        {
            if(isFull()) 
            {
                cout << "Stack list full !";
                return;
            }
            stack[++top] = val;
        }

        void pop()
        {
            if(isEmpty()) 
            {
                cout << "Stack list empty !";
                return;
            }
            cout << "The popped element is : " << stack[--top] << endl;
        }

        void display(string message)
        {
            if(isEmpty()) 
            {
                cout << "Stack list empty !";
                return;
            }
            cout << message << " : ";
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
};


int main()
{
    // Creation of the stack object
    int capacity;
    cout << "- Enter the capacity of the new stack : ";
    cin >> capacity;
    Stack* stack1 = new Stack(capacity);

    // Insert element in the stack
    int nbElement;
    exceedCapacity :
    cout << "- Insert how many element you want to insert into the stack : ";
    cin >> nbElement;
    if(nbElement > capacity || nbElement < 0)
    {
        cout << "Number of elements entered invalid !" << endl;
        goto exceedCapacity;
    }
    int element;
    for (int i = 1; i <= nbElement; i++)
    {
        cout << "Element " << i << " : ";
        cin >> element;
        stack1 -> push(element);
    }

    // Display the stack
    stack1 -> display("- Stack1 : ");
    

    return 0;
}


