#include <iostream>
using namespace std;

void findMajorityElement(int arr[], int N)
{
    int majElements[N/3];
    int k = 0;
    int minLen = N/3;
    int count;
    for (int i = 0; i < N; i++)
    {
        // Check if the element is already in majElements array
        bool alreadyPresent = false;
        for (int a = 0; a < k; a++)
        {
            if(arr[i] == majElements[a]){
                alreadyPresent = true;
                break;
            }
        }
        // If already present, skip this element
        if(alreadyPresent) 
            continue;
        // If not, find the majority element
        count = 0;
        for (int j = i; j < N; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count > minLen)
        {
            majElements[k] = arr[i];
            k++;
        }
    }
    cout << "The majority elements in the array : ";
    for (int i = 0; i < k; i++)
    {
        cout << majElements[i] << " ";
    }
}

int main()
{
    int arr[] = {11, 33, 33,22, 11, 33, 11, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    findMajorityElement(arr, size);
    return 0;
}