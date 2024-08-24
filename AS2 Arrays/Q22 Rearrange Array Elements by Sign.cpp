#include <iostream>
using namespace std;

void rearrangeByType(int arr[], int size) 
{
    int halflen = size/2;
    for (int i = 1; i < halflen; i++) 
    {
        // Logic not correct
        int temp = arr[i];
        arr[i] = arr[halflen + i];
        arr[halflen + i] = temp;
    }
    cout << "After rearranging the array elements by sign : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
     
}

int main()
{
    int A[] = {1 , 2, -4, -5};
    int N = sizeof(A) / sizeof(A[0]);
    rearrangeByType(A, N);
    return 0;
}
