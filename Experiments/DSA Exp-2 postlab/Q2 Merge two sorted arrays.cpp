#include <iostream>
using namespace std;

void sortArray(int arr[], int N) 
{
    for (int i = 0; i < N-1; i++) 
    {
        for (int j = 0; j < N-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int start, int end) 
{
    for (int i = start; i < end; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSortedArray(int arr1[], int arr2[], int size1, int size2)
{
    int finalSize = size1 + size2;
    int mergedA[finalSize];
    for (int i = 0; i < finalSize; i++)
    {
        if(i < size1)
        {
            mergedA[i] = arr1[i];
        }
        else
        {
            mergedA[i] = arr2[i-size1];
        }
    }
    // Sort the array
    sortArray(mergedA, finalSize);
    cout << "After merging and sorting the two sorted arrays : ";
    printArray(mergedA, 0, finalSize);
}

int main()
{
    int arr1[] = {1, 4, 8, 10};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "arr1 : ";
    printArray(arr1, 0, size1);
    int arr2[] = {2, 3, 9};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "arr2 : ";
    printArray(arr2, 0, size2);
    mergeSortedArray(arr1, arr2, size1, size2);
    return 0;
}