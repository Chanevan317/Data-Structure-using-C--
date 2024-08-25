#include <iostream>
using namespace std;

int longestSubarrayWithZeroSum(int arr[], int size) {
    int maxLength = 0;
    for (int i = 0; i < size; i++) {
        int currentSum = 0;
        for (int j = i; j < size; j++) {
            currentSum += arr[j];
            if (currentSum == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main() {
    int arr[] = {6, -2, 2, -8, 1, 7, 4, -10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest subarray with zero sum " << " : " << longestSubarrayWithZeroSum(arr, size) << endl;
    return 0;
}

