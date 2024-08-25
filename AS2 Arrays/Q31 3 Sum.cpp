#include <iostream>
using namespace std;

void sortArray(int arr[], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void findTriplets(int arr[], int N) {
    sortArray(arr, N);
    bool found = false;
    for (int i = 0; i < N - 2; i++) 
    {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        // Create left and right indexes
        int left = i + 1, right = N - 1;
        // Loop to find the triplets
        while (left < right) 
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0) 
            {
                cout << "[" << arr[i] << ", " << arr[left] << ", " << arr[right] << "]" << endl;
                found = true;
                // Move left and right to skip duplicate numbers
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++;
                right--;
            } 
            else if (sum < 0) 
            {
                left++;
            } 
            else 
            {
                right--;
            }
        }
    }
    if (!found) {
        cout << "No triplets found that add up to a zero." << endl;
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Unique triplets that add up to a zero are : " << endl;
    findTriplets(nums, size);
    return 0;
}
