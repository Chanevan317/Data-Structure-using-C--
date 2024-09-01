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

        int find_kth_smallest(int k) {
            Node* current = head;
            int count = 1;
            while (current != nullptr) {
                if (count == k) return current->Data;
                current = current->Next;
                count++;
            }
            throw out_of_range("K is out of bounds");
        }

        Node* get_head() const {
            return head;
        }
};

int main() {
    LinkedList list;
    int arr[7] = {1, 3, 5, 6, 9, 10, 12};
    for (int i = 0; i < 7; i++) {
        list.insert_at_end(arr[i]);
    }
    list.traverse("List : ");
    
    try {
        int k = 3;
        cout << "The " << k << "-th smallest element is : " << list.find_kth_smallest(k) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}

