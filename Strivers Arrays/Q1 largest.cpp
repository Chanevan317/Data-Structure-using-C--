#include <iostream>
using namespace std;

int largest(int arr[], int size){
	int largest = arr[0];
	for(int i = 1; i < size; i++){		
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	return largest;
}

int main(){
	int arr[10] = {1,8,8,7,20,9,10,11,12,1};
	cout << "Your array : ";
    for(int i = 0; i < 10; i++){
    	cout << arr[i] << " ";
	}
	cout << "\n\nThe largest element of the array is : " << largest(arr, 10) << ".";
	return 0;	
}
