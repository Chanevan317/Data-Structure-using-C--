#include <iostream>
using namespace std;

void display_array(int arr[], int size){
    cout << "The array elements are : ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search_array(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int insert_element(int arr[], int& size, int capacity, int element, int pos_ins){
    if(size >= capacity){
        cout << "The array is full." << endl;
        return -1;    
    }
    if(pos_ins < 0 || pos_ins > size){
        cout << "Invalid position specified." << endl;
        return -1;
    }
    for(int i = size; i > pos_ins; i--){
        arr[i] = arr[i-1];
    }
    arr[pos_ins] = element;
    size++;
    return 0;
}

int delete_element(int arr[], int& size, int pos_del){
	
	if(pos_del < 0 || pos_del > size){
		cout << "Invalid position specified." << endl;
        return -1;
	}
	for(int i = pos_del; i < size; i++){
		arr[i] = arr[i+1];
	}
	size--;
	return 0;
	
}


int main(){
    int capacity = 10;
    int size = 5;
    int arr[capacity] = {2, 5, 1, 4, 7};
    
    // Display the array
    display_array(arr, size);
    
    // Search an element
    int key = 4;
    int index = search_array(arr, size, key);
    cout << "- Searching the element " << key << "." << endl;
    if(index != -1){
        cout << "The element " << key << " is present at the index " << index << "." << endl;
    }else{
        cout << "Element " << key << " not found !" << endl;
    } 
    
    // Insert element
    int element = 3;
    int pos_ins = 2;
    insert_element(arr, size, capacity, element, pos_ins);
    cout << "- Inserting " << element << " at the index " << pos_ins << "." << endl;
    display_array(arr, size);
    
    // Delete element
    int pos_del = 1;
    delete_element(arr, size, pos_del);
    cout << "- Deleting the element at the index " << pos_del << "." << endl;
    display_array(arr, size);
    
    return 0;
}

