#include <iostream>
using namespace std;

int repeatNbyTwo(int arr[], int size) {
	int N;
	if(size%2 == 0){
		N = size/2;
	}else{
		N = size/2 + 1;
	}
	int count = 0;
 	for(int i = 0; i < size; i++){
 		for(int j = 0; j < size; j++){
 			if(arr[j] == arr[i]){
 				count++;
			}
		}
		if(count >= N){
			return arr[i];
		}
		count = 0;
	}
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The element that occura more than N/2 is " << repeatNbyTwo(arr, size) << endl;
    return 0;
}

