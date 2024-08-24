#include <iostream>
using namespace std;

int singleNumber(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr1[] = {2, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "The number that appears once in arr1 : " << singleNumber(arr1, size1) << endl;

    int arr2[] = {4, 1, 2, 1, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "The number that appears once in arr2 : " << singleNumber(arr2, size2) << endl;

    return 0;
}

