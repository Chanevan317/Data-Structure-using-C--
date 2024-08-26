#include <iostream>
using namespace std;

void mergeSubIntervals(int I[][2], int rows, int maxRows)
{
    int mergedI[maxRows][2];
    int len = 0;
    mergedI[0][0] = I[0][0];
    mergedI[0][1] = I[0][1];
    len = 1;
    for (int i = 1; i < rows; i++) 
    {
        if (mergedI[len-1][1] >= I[i][0]) 
        {
            // Merge the intervals
            mergedI[len-1][1] = max(mergedI[len-1][1], I[i][1]);
        } 
        else 
        {
            // Add new interval
            mergedI[len][0] = I[i][0];
            mergedI[len][1] = I[i][1];
            len++;
        }
    }
    cout << "After merging the intervals : " << endl;
    for (int i = 0; i < len; i++) 
    {
        cout << mergedI[i][0] << " " << mergedI[i][1] << endl;
    }
}

int main()
{
    int MAX = 25;
    int interval[][2] = {{1,3},
                            {2,6},
                            {8,10},
                            {15,18}};

    mergeSubIntervals(interval, 4, MAX);
    return 0;
}