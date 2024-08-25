#include <iostream>
using namespace std;

void longestConsecutive(int arr[], int size) 
{
    int next, count;
    int longest = 0;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        next = i;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == next+1)
            {
                next++;
                count++;                    
                j = -1;
            }
        }
        longest = max(count, longest);
    }
    cout << "The length of the longest consecutive sequence in the array is " << longest << endl;
}

int main()
{
    int arr1[] = {3, 8, 5, 7, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    longestConsecutive(arr1, size1);
    int arr2[] = {6, 100, 200, 1, 3, 2, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    longestConsecutive(arr2, size2);
    return 0;
}
