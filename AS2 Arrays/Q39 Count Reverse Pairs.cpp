#include <iostream>
using namespace std;

int countReversePair(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if(arr[i] > 2*arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr1[] = {1,3,2,3,1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "The count of reverse pair in arr1 is " << countReversePair(arr1, size1) << endl;

    int arr2[] = {3,2,1,4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "The count of reverse pair in arr2 is " << countReversePair(arr2, size2) << endl;

    return 0;
}

