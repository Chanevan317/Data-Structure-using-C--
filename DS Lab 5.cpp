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
		
		void merge_sorted(Node* list1, Node* list2){
			LinkedList result;
			while(list1 != nullptr && list2 != nullptr){
				if(list1 -> Data < list2 -> Data){
					result.insert_at_end(list1 -> Data);
					list1 = list1 -> Next;
				}else{
					result.insert_at_end(list2 -> Data);
					list2 = list2 -> Next;
				}
			}
			while(list1 != nullptr){
				result.insert_at_end(list1 -> Data);
				list1 = list1 -> Next;
			}
			while(list2 != nullptr){
				result.insert_at_end(list2 -> Data);
				list2 = list2 -> Next;
			}
		}
		
		// Get the linked list head address
		Node* getHead(){
			return head;
		}
		
		void display(string message){
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
	
	// Create list1
	LinkedList list1;
	int arr1[6] = {1, 6, 8, 14, 16, 20};
	for(int i = 0; i < 6; i++){
		list1.insert_at_end(arr1[i]);
	}
	list1.display("Linked list 1 : ");
	
	// Create list2
	LinkedList list2;
	int arr2[4] = {2, 5, 18, 22};
	for(int i = 0; i < 4; i++){
		list2.insert_at_end(arr2[i]);
	}
	list2.display("Linked list 2 : ");
	
	LinkedList result;
	result.merge_sorted(list1.getHead(), list2.getHead());
	result.display("Merging the 2 linked lists : ");
	
	return 0;
}

