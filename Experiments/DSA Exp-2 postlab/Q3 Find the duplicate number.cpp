#include <iostream>
using namespace std;

int findDuplicate(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {1, 2, 3, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int duplicate = findDuplicate(arr, size);
    
    if (duplicate != -1) 
    {
        cout << "The duplicate number is : " << duplicate << endl;
    } 
    else 
    {
        cout << "No duplicate found." << endl;
    }
    
    return 0;
}
