#include <iostream>
using namespace std;

void spiralTraversal(int matrix[][4], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) 
    {
        // Traverse from left to right
        for (int i = left; i <= right; i++) 
        {
            cout << matrix[top][i] << " ";
        }
        top++;
        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) 
        {
            cout << matrix[i][right] << " ";
        }
        right--;
        // Traverse from right to left
        if (top <= bottom) 
        {
            for (int i = right; i >= left; i--) 
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        // Traverse from bottom to top
        if (left <= right) 
        {
            for (int i = bottom; i >= top; i--) 
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    int matrix1[4][4] = { {1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16} };

    cout << "Spiral Traversal of Matrix 1 :" << endl;
    spiralTraversal(matrix1, 4, 4);
    return 0;
}
