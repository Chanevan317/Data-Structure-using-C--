#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
  	for (int i = 1; i < size; i++) {
    	if (arr[i] < arr[i - 1])
      		return false;
  	}
  	return true;
}

int main() {

  	int arr[5] = {1, 2, 3, 4, 5};
  	if(isSorted(arr, 5)){
  		cout << "The array is sorted." << endl;
  	}else{
  		cout << "The array is not sorted." << endl;
  	}
	return 0;
}


