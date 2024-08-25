#include <iostream>
using namespace std;

void maxSubarraySum(int arr[], int size) 
{
    int maxSum = 0;
    int index1, index2;
    for (int i = 0; i < size; i++) 
    {
        int sum = 0;
        for (int j = i; j < size; j++) 
        {
            sum += arr[j];
            if(sum > maxSum)
            {
                maxSum = sum;
                index1 = i;
                index2 = j;
            }
        }
    }
    cout << "The maximum subarray sum in the array is : " << maxSum << endl;
    cout << "The subarray is : ";
    for (int i = index1; i <= index2 ; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxSubarraySum(arr, size);
    return 0;
}

