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
    int arr[] = {5, 2, 2, 5, 1, 9, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    cout << "Length of the longest subarray with sum " << k << " : " << longestSubarrayWithSumK(arr, size, k) << endl;
    return 0;
}

