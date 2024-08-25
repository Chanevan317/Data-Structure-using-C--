#include <iostream>
using namespace std;

void countSubarrayWithSumK(int arr[], int N, int k) 
{
    int cnt = 0;
    int sum;
    for (int i = 0; i < N; i++) 
    {
        sum = 0;
        for (int j = i; j < N; j++) {
            sum += arr[j];
            if (sum == k) 
            {
                cnt++;
                break;
            }
        }
    }
    cout << "The number of subarrays having the sum equals to " << k << " is " << cnt << endl;
}

int main() 
{
    int arr1[] = {3, 1, 2, 4};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 6;
    cout << "Array 1 :  ";
    countSubarrayWithSumK(arr1, size, k);

    int arr2[] = {1 ,2 ,3};
    size = sizeof(arr2) / sizeof(arr2[0]);
    k = 3;
    cout << "Array 2 :  ";
    countSubarrayWithSumK(arr2, size, k);

    return 0;
}

