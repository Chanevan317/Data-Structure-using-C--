#include <iostream>
using namespace std;

void findMajorityElement(int arr[], int N)
{
    int halfLen = N/2;
    int count = 0;
    int element;
    for(int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count >= halfLen)
        {
            element = arr[i];
        }
        count = 0;
    }
    cout << "The majority element in the array is " << element << endl;
}

int main()
{
    int nums[] = {2, 2, 1, 1, 3, 1, 2, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    findMajorityElement(nums, size);
    return 0;
}