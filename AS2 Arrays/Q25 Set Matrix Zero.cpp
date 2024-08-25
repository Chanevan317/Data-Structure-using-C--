#include <iostream>
#include <vector>
using namespace std;

void setZeroMatrix(int M[][4], int row, int col) 
{
    vector<int> zRow = {};
    vector<int> zCol = {};
    int cntZero = 0;
    // Find the position of the zeros
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(M[i][j] == 0)
            {
                cout << "0 found at " << i+1 << "," << j+1 << endl;
                zRow.push_back(i);
                zCol.push_back(j);
                cntZero++;
            }
        }
    }
    for(int i = 0; i < cntZero; i++) 
    {
        // Make the row zero
        for (int c = 0; c < col; c++)
        {
            M[zRow[i]][c] = 0;
        }
        // Make the col zero
        for (int r = 0; r < row; r++)
        {
            M[r][zCol[i]] = 0;
        }
    }
}

void display_matrix(int M[][4], int row, int col)
{
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][4] = {{0,1,2,0},
                        {3,4,5,2},
                        {1,3,1,5}};
    
    setZeroMatrix(matrix, 3, 4);
    cout << "Result matrix : " << endl;
    display_matrix(matrix, 3, 4);
    return 0;
}
