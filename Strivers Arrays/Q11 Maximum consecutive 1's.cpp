#include <iostream>
using namespace std;

int countMaxConsecutiveOnes(int arr[], int size) {
    int maxCount = 0;
    int currentCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }
    return maxCount;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum consecutive 1's: " << countMaxConsecutiveOnes(arr, size) << endl;
    return 0;
}
