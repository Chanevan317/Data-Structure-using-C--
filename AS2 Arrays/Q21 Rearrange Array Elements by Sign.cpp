#include <iostream>
using namespace std;

void rearrangeByType(int arr[], int size) 
{
    int arrangedArray[size];
    int posPtr = 0, negPtr = 1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            arrangedArray[negPtr] = arr[i];
            negPtr += 2; 
        }
        else
        {
            arrangedArray[posPtr] = arr[i];
            posPtr += 2;
        }
    }
    cout << endl << "After rearranging the array by sign : ";
    for (int i = 0; i < size; i++)
    {
        cout << arrangedArray[i] << " ";
    }
    
}

int main()
{
    int A[] = {1 , 2, -4, -5};
    int Na = sizeof(A) / sizeof(A[0]);
    rearrangeByType(A, Na);
    int B[] = {1, 2, -3, -1, -2, 3};
    int Nb = sizeof(B) / sizeof(B[0]);
    rearrangeByType(B, Nb);
    return 0;
}
