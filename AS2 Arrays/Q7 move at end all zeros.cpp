#include <iostream>
using namespace std;

void moveZeroAtEnd(int arr[], int size) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }
    while (index < size) {
        arr[index++] = 0;
    }
}

int main() {
    int arr[8] = {0, 1, 0, 0, 12, 0, 5, 0};
    moveZeroAtEnd(arr, 8);
    cout << "Moving all zeros at the end : " << endl;
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}

