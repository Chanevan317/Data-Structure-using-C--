#include <iostream>
using namespace std;

class Node
{
    private :
        int Data;
        Node* Next;
        Node* Prev;

    public :
        Node(int val)
        {
            Data = val;
            Next = nullptr;
            Prev = nullptr;
        }
};

class DLL 
{
    private:
		Node* head;
	
	public:
		DLL()
        {
			head = nullptr;
		}

        void traverse(string message)
        {
			if(head == nullptr)
            {
				cout << "Doubly linked list empty !" << endl;
				return;
			}
			Node* temp = head;
			cout << message << endl;
			while(temp != nullptr)
            {
				cout << temp -> Data << " ";
				temp = temp -> Next;
			}
			cout << endl;
		}

        void search(int key)
        {
            Node* temp = head;
            int count = 1;
			while(temp != nullptr)
            {
				if(temp -> Data == key) 
                {
                    cout << "The element " << key << " is found at index " << count << "." << endl;
                    return;
                }
                count++;
				temp = temp -> Next;
			}
            cout << "The element " << key << " is not found in the doubly linked list." << endl;
            return;
        }

        void insertAtBegin(int data)
        {
            Node* newNode = new Node(data);
            if(head == nullptr)
            {
                head = newNode;
                return;
            }
			newNode -> Next = head;
            newNode -> Next -> Prev = newNode;
            head = newNode;
        }

        void insertAtEnd(int val)
        {
            
        }
};

int main()
{
    // Create the doubly linked list
    DLL dll1;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        dll1.insertAtEnd(i);
    }
    delete arr;
    
}