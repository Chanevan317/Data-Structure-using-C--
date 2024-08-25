#include <iostream>
using namespace std;

void leaders(int arr[], int size) 
{
    cout << "Leaders in the given array : ";
    for (int i = 0; i < size; i++)
    {
        bool isLeader = false;
        for (int j = i+1; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                isLeader = false;
                break;
            }
            else{
                isLeader = true;
            }
        }
        if(isLeader == true)
        {
            cout << arr[i] << " ";
        }
    }
    cout << arr[size-1] << endl;
}

int main()
{
    int arr[] = {10, 22, 12, 3, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    leaders(arr, size);
    return 0;
}
