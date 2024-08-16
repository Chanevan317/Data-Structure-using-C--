#include <iostream>
using namespace std;

void unionSortedArrays(int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0;
    int prev = -1;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            if (arr1[i] != prev) {
                cout << arr1[i] << " ";
                prev = arr1[i];
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (arr2[j] != prev) {
                cout << arr2[j] << " ";
                prev = arr2[j];
            }
            j++;
        } else {
            if (arr1[i] != prev) {
                cout << arr1[i] << " ";
                prev = arr1[i];
            }
            i++;
            j++;
        }
    }
    while (i < size1) {
        if (arr1[i] != prev) {
            cout << arr1[i] << " ";
            prev = arr1[i];
        }
        i++;
    }
    while (j < size2) {
        if (arr2[j] != prev) {
            cout << arr2[j] << " ";
            prev = arr2[j];
        }
        j++;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    cout << "Union of arr1 and arr2 : " << endl;
    unionSortedArrays(arr1, arr2, 10, 7);

    return 0;
}
