#include <iostream>
using namespace std;

int missingNumber(int arr[], int size) {
    int N = size;
    int expectedSum = N * (N + 1) / 2;
    int sum = 0;
    for (int i = 0; i < size-1; i++) {
        sum += arr[i];
    }
    return expectedSum - sum;
}

int main() {
    int arr1[4] = {1, 2, 4, 5};
    cout << "Missing number : " << missingNumber(arr1, 4) << endl;

    int arr2[3] = {1, 3, 4}; 
    cout << "Missing number : " << missingNumber(arr2, 3) << endl;

    return 0;
}

