#include <iostream>
using namespace std;

void findMajorityElement(int arr[], int size)
{
    int halfLen = size/2;
    int count = 0;
    int element;
    for(int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
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