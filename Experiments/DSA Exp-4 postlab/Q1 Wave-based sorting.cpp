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

        void reorder_wave() {
            if (head == nullptr || head->Next == nullptr) return;

            // Find the length of the linked list
            Node* temp = head;
            int count = 0;
            while (temp != nullptr) {
                count++;
                temp = temp->Next;
            }

            // Store its data in an array
            int* arr = new int[count];
            temp = head;
            for (int i = 0; i < count; i++) {
                arr[i] = temp->Data;
                temp = temp->Next;
            }

            // Rebuild the linked list in wave pattern
            int start = 0, end = count - 1;
            temp = head;
            while (start <= end) {
                if (temp != nullptr) {
                    temp->Data = arr[start++];
                    temp = temp->Next;
                }
                if (temp != nullptr) {
                    temp->Data = arr[end--];
                    temp = temp->Next;
                }
            }
            delete[] arr;
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    LinkedList list;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        list.insert_at_end(arr[i]);
    }
    list.traverse("Original List : ");
    list.reorder_wave();
    list.traverse("Reordered List : ");
    
    return 0;
}
