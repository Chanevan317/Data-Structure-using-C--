#include <iostream>
using namespace std;

int longestSubarrayWithSumK(int arr[], int size, int k) {
    int maxLength = 0;
    for (int i = 0; i < size; i++) {
        int currentSum = 0;
        for (int j = i; j < size; j++) {
            currentSum += arr[j];
            if (currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main() {
    int arr1[] = {2, 3, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 5;
    cout << "Length of the longest subarray with sum " << k1 << ": " << longestSubarrayWithSumK(arr1, size1, k1) << endl;

    int arr2[] = {-1, 1, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 1;
    cout << "Length of the longest subarray with sum " << k2 << ": " << longestSubarrayWithSumK(arr2, size2, k2) << endl;

    return 0;
}

