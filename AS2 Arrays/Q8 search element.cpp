#include <iostream>
using namespace std;

int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int key = 4;
    int index = search(arr, 8, key);
    if(index > -1){
    	cout << "The element " << key << " is at the index " << index << "." << endl;
	}else if (index == -1){
		cout << "The element " << key << " does not exist in the array." << endl;
	}
    return 0;
}

