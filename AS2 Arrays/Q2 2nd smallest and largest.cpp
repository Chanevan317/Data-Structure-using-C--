#include <iostream>
using namespace std;

int secondSmallest(int arr[], int size){
	
	int smallest = arr[0], sec_smallest;
	for(int i = 1; i < size; i++){		
		if(arr[i] < smallest){
			sec_smallest = smallest;
			smallest = arr[i];
		}
	}
	if(smallest == arr[0]){
		sec_smallest = arr[1];
		for(int i = 2; i < size; i++){
			if(arr[i] < sec_smallest){
				sec_smallest = arr[i];
			}
	    }		
	}
	return sec_smallest;
	
}

int secondLargest(int arr[], int size){
	
	int largest = arr[0], sec_largest;
	for(int i = 1; i < size; i++){		
		if(arr[i] > largest){
			sec_largest = largest;
			largest = arr[i];
		}
	}
	if(largest == arr[0]){
		sec_largest = arr[1];
		for(int i = 2; i < size; i++){
			if(arr[i] > sec_largest){
				sec_largest = arr[i];
			}
	    }		
	}
	return sec_largest;
	
}

int main(){
	
	int arr1[10] = {1,8,8,7,8,9,10,11,12,13};
	cout << "Your array : ";
    for(int i = 0; i < 10; i++){
    	cout << arr1[i] << " ";
	}
	cout << "\n\nThe second smallest element in the array is : " << secondSmallest(arr1, 10) << ".";
	cout << "\n\nThe second largest element in the array is : " << secondLargest(arr1, 10) << ".";
	return 0;
}
