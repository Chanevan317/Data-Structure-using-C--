#include <iostream>
using namespace std;

int numberSubarrayWithXorK(int arr[], int size, int k) {
    int number = 0;
    for (int i = 0; i < size; i++) {
        int xorRes = 0;
        for (int j = i; j < size; j++) {
            xorRes ^= arr[j];
            if (xorRes == k) {
                number++;
            }
        }
    }
    return number;
}

int main() {
    int arr[] = {4, 2, 2, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << "Number of subarray with xor " << k << " : " << numberSubarrayWithXorK(arr, size, k) << endl;
    return 0;
}

