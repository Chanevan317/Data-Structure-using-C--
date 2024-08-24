#include <iostream>
#include<array>
using namespace std;

array<int,3> twoSum(int arr[], int size, int target) {
	array<int,3> res;
    for(int i = 0; i < size-1; i++){
    	for(int j = i+1; j < size; j++){
    		if(arr[i] + arr[j] == target){
    			return res = {1, i, j};
			}
		}
	}
	return res = {0, -1, -1};
}

int main() {
    int arr[] = {2, 6, 5, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;
    array<int,3> res = twoSum(arr, size, target);
    if(res[0] == 1){
    	cout << "YES" << endl;
    	cout << "[" << res[1] << ", " << res[2] << "]";
	}else if(res[0] == 0){
		cout << "NO" << endl;
		cout << "[" << res[1] << ", " << res[2] << "]";
	}
    return 0;
}

