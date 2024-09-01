#include <iostream>
#include <vector>
using namespace std;

void rotate90Image(int M[][4], int row, int col) 
{
    cout << "Rotated matrix : " << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << M[j][i] << " ";
        }
        cout << endl;
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
    int matrix[4][4] = {{5,1,9,11},
                        {2,4,8,10},
                        {13,3,6,7},
                        {15,14,12,16}};

    cout << "Original matrix : " << endl;
    display_matrix(matrix, 4, 4);
    rotate90Image(matrix, 4, 4);
    return 0;
}

