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
    int count = index2 - index1 + 1;
    cout << "The length of the maximum subarray sum in the array is : " << count << endl;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxSubarraySum(arr, size);
    return 0;
}

