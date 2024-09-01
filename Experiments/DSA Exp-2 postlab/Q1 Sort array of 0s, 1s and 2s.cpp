#include <iostream>
using namespace std;

void sortArray(int arr[], int size) 
{
    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 0) 
        {
            zero++;
        } 
        else if(arr[i] == 1) 
        {
            one++;
        } 
        else if(arr[i] == 2) 
        {
            two++;
        }
    }
    for(int i = 0; i < size; i++) 
    {
        if(i < zero) 
        {
            arr[i] = 0;
        } 
        else if(i < zero + one) 
        {
            arr[i] = 1;
        } 
        else 
        {
            arr[i] = 2;
        }
    }
}

int main() 
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size);
    cout << "Sorted array: " << endl;
    for(int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    return 0;
}

