#include <iostream>
using namespace std;

void sortArray(int arr[], int N) 
{
    for (int i = 0; i < N-1; i++)
        for (int j = 0; j < N-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void findQuadruplets(int arr[], int N, int target) 
{
    sortArray(arr, N);
    for (int i = 0; i < N - 3; i++) 
    {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < N - 2; j++) 
        {
            // Skip duplicates for the second element
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            // Create left and right indexes
            int left = j + 1, right = N - 1;
            // Loop to find the quadruplets
            while (left < right)
            {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target) 
                {
                    cout << "[" << arr[i] << ", " << arr[j] << ", " << arr[left] << ", " << arr[right] << "]" << endl;
                    // Move left and right to skip duplicate numbers
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++; 
                    right--;
                } 
                else if (sum < target)
                { 
                    left++; 
                }
                else 
                {
                    right--;
                }
            }
        }
    }
}

int main() {
    int nums[] = {4 ,3 ,3, 4, 4, 2, 1, 2, 1, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    cout << "Unique quadruplets that add up to the target " << target << " are : " << endl;
    findQuadruplets(nums, size, target);
    return 0;
}
