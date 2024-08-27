#include <iostream>
using namespace std;

int maxProductSubarray(int arr[], int size) {
    int maxProduct = 0;
    for (int i = 0; i < size; i++) {
        int currentProduct = 1;
        for (int j = i; j < size; j++) {
            if(i == 0 && j == size - 1) break;
            currentProduct *= arr[j];
            maxProduct = max(maxProduct, currentProduct);
        }
    }
    return maxProduct;
}

int main() {
    int arr1[] = {1 , 2, 3, 4, 5, 0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "The maximum subarray product in arr1 is " << maxProductSubarray(arr1, size1) << endl;

    int arr2[] = {1 , 2, -3, 0, -4, -5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "The maximum subarray product in arr2 is " << maxProductSubarray(arr2, size2) << endl;

    return 0;
}

