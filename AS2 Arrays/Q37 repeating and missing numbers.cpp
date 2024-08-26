#include <iostream>
using namespace std;

void repeatingNumber(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] == arr[i])
            {
                cout << "- Repeating number A = " << arr[i] << endl;
                return;
            }
        }
    }
    cout << "There is no repeating number." << endl;
}

void missingNumber(int arr[], int size) 
{
    int expectedNb = 1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == expectedNb)
        {
            expectedNb++;
            i = -1;
        }
    }
    cout << "- Missing number B = " << expectedNb << endl;
}

int main() {
    int arr1[] = {3 , 1, 2, 5, 3};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "In arr1 : " << endl;
    repeatingNumber(arr1, size1);
    missingNumber(arr1, size1);

    int arr2[] = {3, 1, 2, 5, 4, 6, 7, 5}; 
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "In arr2 : " << endl;
    repeatingNumber(arr2, size2);
    missingNumber(arr2, size2);

    return 0;
}

