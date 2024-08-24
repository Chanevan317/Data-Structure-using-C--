#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int size)
{
  	int i = 0;
  	for (int j = 1; j < size; j++) {
    	if (arr[i] != arr[j]) {
      		i++;
      		arr[i] = arr[j];
    	}
  	}
  	return i + 1;
}

int main() {
  	int arr[14] = {1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5};
  	int k = removeDuplicates(arr, 14);
  	cout << "The array after removing duplicate elements is : " ;
  	for (int i = 0; i < k; i++) {
    	cout << arr[i] << " ";
  	}
  	return 0;
}
