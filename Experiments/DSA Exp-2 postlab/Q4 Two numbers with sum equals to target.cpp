#include <iostream>
using namespace std;

pair<string, pair<int, int>> findPairWithSum(int arr[], int size, int target) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = i + 1; j < size; ++j) 
        {
            if (arr[i] + arr[j] == target) 
            {
                return {"YES", {i, j}};
            }
        }
    }
    return {"NO", {-1, -1}};
}

int main() 
{
    int arr[] = {2, 7, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    auto result = findPairWithSum(arr, size, target);
    cout << result.first << endl;
    if (result.first == "YES") 
    {
        cout << "Indices with sum  equals to " << target << " : " << result.second.first << ", " << result.second.second << endl;
    } 
    else 
    {
        cout << "No indices with sum equals to " << target << endl;
    }

    return 0;
}

