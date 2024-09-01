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

        void merge_sorted_lists(LinkedList& list2) {
            Node* p1 = head;
            Node* p2 = list2.head;

            if (p1 == nullptr) {
                head = p2;
                return;
            }
            if (p2 == nullptr) {
                return;
            }

            if (p1->Data <= p2->Data) {
                head = p1;
                p1 = p1->Next;
            } else {
                head = p2;
                p2 = p2->Next;
            }

            Node* current = head;

            while (p1 != nullptr && p2 != nullptr) {
                if (p1->Data <= p2->Data) {
                    current->Next = p1;
                    p1 = p1->Next;
                } else {
                    current->Next = p2;
                    p2 = p2->Next;
                }
                current = current->Next;
            }

            if (p1 != nullptr) {
                current->Next = p1;
            } else {
                current->Next = p2;
            }
        }

        Node* get_head() const {
            return head;
        }
};

int main() {
    LinkedList list1;
    list1.insert_at_end(1);
    list1.insert_at_end(3);
    list1.insert_at_end(5);

    LinkedList list2;
    list2.insert_at_end(2);
    list2.insert_at_end(4);
    list2.insert_at_end(6);

    list1.traverse("List 1 : ");
    list2.traverse("List 2 : ");

    list1.merge_sorted_lists(list2);
    list1.traverse("Merged List : ");

    return 0;
}
