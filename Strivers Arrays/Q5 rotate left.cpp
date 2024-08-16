#include <iostream>
using namespace std;

void leftRotate(int arr[], int size)
{
	int first_element = arr[0];
	for(int i = 1; i < size; i++){
		arr[i-1] = arr[i];
	}
	arr[size-1] = first_element;
}

int main() {
  	int arr[6] = {1, 2, 3, 4, 5, 6};
  	leftRotate(arr, 6);
  	cout << "The left rotated array is : " << endl;
  	for (int i = 0; i < 6; i++) {
   	 	cout << arr[i] << " ";
  	}
  	return 0;
}
