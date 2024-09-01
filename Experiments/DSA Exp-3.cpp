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

class LinkedList{
	private:
		Node* head;
	
	public:
		LinkedList(){
			head = nullptr;
		}
		
		void insert_at_begin(int data){
			Node* new_node = new Node(data);
			new_node -> Next = head;
			head = new_node;
		}
		
		void insert_at_end(int data){
			Node* new_node = new Node(data);
			if(head == nullptr){
				head = new_node;
				return;
			}
			Node* temp = head;
			while(temp -> Next != nullptr){
				temp = temp -> Next;
			}
			temp -> Next = new_node;
		}
		
		void insert_between(int val, int pos){
			if(pos < 0){
				cout << "Entered position invalid !" << endl;
				return;
			}
			if(pos == 0){
				insert_at_begin(val);
				return;
			}
			Node* temp = head;
			int currentPos = 1;
			while(currentPos < pos && temp -> Next != nullptr){
				temp = temp -> Next;
				currentPos++;
				if(temp -> Next == nullptr){
					cout << "Position greater than Linked List size.";
					return;
				}
			}
			Node* new_node = new Node(val);
			new_node -> Next = temp -> Next;
			temp -> Next = new_node;
		}

        void delete_at_begin() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->Next;
        delete temp;
    }

    void delete_at_end() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        if (head->Next == nullptr) { // Only one element
            delete_at_begin();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->Next != nullptr) {
            prev = temp;
            temp = temp->Next;
        }
        prev->Next = nullptr;
        delete temp;
    }

    void delete_between(int pos) {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        if (pos < 0) {
            cout << "Invalid position   !" << endl;
            return;
        }
        if (pos == 0) {
            delete_at_begin();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        int currentPos = 0;
        while (temp != nullptr && currentPos < pos) {
            prev = temp;
            temp = temp->Next;
            currentPos++;
        }
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        prev->Next = temp->Next;
        delete temp;
    }
		
		bool searching(int key){
			if(head == nullptr){
				cout << "Linked list doesn't exist" << endl;
				return 0;
			}
			Node* temp = head;
			while(temp != nullptr){
				if(temp -> Data == key){
					return true;
				}
				temp = temp -> Next;
			}
			return false;
		}
		
		void traverse(string message){
			if(head == nullptr){
				cout << "Linked list empty !" << endl;
				return;
			}
			Node* temp = head;
			cout << message << endl;
			while(temp != nullptr){
				cout << temp -> Data << " ";
				temp = temp -> Next;
			}
			cout << endl;
		}
	
};

int main(){
	
	LinkedList list;
	int arr[10] = {1, 9, 7, 8, 3, 9, 6, 9, 11 ,25};
	for(int i = 0; i < 10; i++){
		list.insert_at_end(arr[i]);
	}
	list.traverse("Linked list : ");
	// Search an element
	int key = 8;
	bool search = list.searching(key);
	cout << "Searching " << key << " ..." << endl; 
	if(search == true){
		cout << key << " is present in the linked list." << endl;
	}else if(search == false){
		cout << key << " is not present in the linked list." << endl;
	}
	// Insert in between
	list.insert_between(5, 4);
	list.traverse("After inserting 5 at position 4 : ");
    // Delete in between
	list.delete_between(2);
	list.traverse("After deleting the element at position 2 : ");
	
	return 0;
}

