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

        int count_nodes() {
            int count = 0;
            Node* temp = head;
            while (temp != nullptr) {
                count++;
                temp = temp->Next;
            }
            return count;
        }

        void count_odd_even(int &odd_count, int &even_count) {
            odd_count = 0;
            even_count = 0;
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->Data % 2 == 0) {
                    even_count++;
                } else {
                    odd_count++;
                }
                temp = temp->Next;
            }
        }

        void split_odd_even(LinkedList &oddList, LinkedList &evenList) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->Data % 2 == 0) {
                    evenList.insert_at_end(temp->Data);
                } else {
                    oddList.insert_at_end(temp->Data);
                }
                temp = temp->Next;
            }
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
};

int main() {
    LinkedList list;
    int arr[10] = {1, 9, 7, 8, 3, 9, 6, 9, 11, 25};
    for (int i = 0; i < 10; i++) {
        list.insert_at_end(arr[i]);
    }
    list.traverse("Original linked list: ");

    // Count nodes
    int nodeCount = list.count_nodes();
    cout << "Number of nodes in the linked list : " << nodeCount << endl;

    // Count odd and even
    int oddCount, evenCount;
    list.count_odd_even(oddCount, evenCount);
    cout << "Number of Odd number : " << oddCount << endl << "Number of Even number : " << evenCount << endl;

    // Split into odd and even lists
    LinkedList oddList, evenList;
    list.split_odd_even(oddList, evenList);
    oddList.traverse("Odd elements list : ");
    evenList.traverse("Even elements list : ");

    return 0;
}
