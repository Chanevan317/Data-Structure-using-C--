#include <iostream>
using namespace std;

class Node{
	public:
		int Data;
		Node* Next;
		Node(int val){
			Data = val;
			Next = nullptr;
		}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void insert_at_end(int data) {
            Node* new_node = new Node(data);
            if (head == nullptr) {
                head = new_node;
                return;
            }
            Node* temp = head;
            while (temp->Next != nullptr) {
                temp = temp->Next;
            }
            temp->Next = new_node;
        }

        void traverse(string message) {
            if (head == nullptr) {
                cout << "Linked list empty!" << endl;
                return;
            }
            Node* temp = head;
            cout << message << endl;
            while (temp != nullptr) {
                cout << temp->Data << " ";
                temp = temp->Next;
            }
            cout << endl;
        }

        void remove_duplicates() {
            Node* current = head;
            while (current != nullptr && current->Next != nullptr) {
                if (current->Data == current->Next->Data) {
                    Node* duplicate = current->Next;
                    current->Next = current->Next->Next;
                    delete duplicate;
                } else {
                    current = current->Next;
                }
            }
        }

        Node* get_head() const {
            return head;
        }
};

int main() {
    LinkedList list;
    int arr[8] = {1, 1, 2, 3, 3, 4, 5, 5};
    for (int i = 0; i < 8; i++) {
        list.insert_at_end(arr[i]);
    }
    list.traverse("Original List : ");
    
    list.remove_duplicates();
    list.traverse("List after removing duplicates : ");
    
    return 0;
}

            