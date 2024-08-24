#include <iostream>
using namespace std;

void leftRotate(int arr[], int size, int k)
{
	for(int l = 0; l < k; l++){
		int first_element = arr[0];
		for(int i = 1; i < size; i++){
			arr[i-1] = arr[i];
		}
		arr[size-1] = first_element;
	}
}

void rightRotate(int arr[], int size, int k)
{
	for(int r = 0; r < k; r++){
		int last_element = arr[size-1];
		for(int i = size-1; i > 0; i--){
			arr[i] = arr[i-1];
		}
		arr[0] = last_element;
	}
}

int main() {
  	int arr1[6] = {1, 2, 3, 4, 5, 6};
  	int arr2[6] = {1, 2, 3, 4, 5, 6};
  	int k = 2;
  	leftRotate(arr1, 6, k);
  	rightRotate(arr2, 6, k);
  	cout << "Left rotated " << k << " times : " << endl;
  	for (int i = 0; i < 6; i++) {
   	 	cout << arr1[i] << " ";
  	}
  	cout << endl << "Right rotated " << k << " times : " << endl;
  	for (int i = 0; i < 6; i++) {
   	 	cout << arr2[i] << " ";
  	}
  	return 0;
}
