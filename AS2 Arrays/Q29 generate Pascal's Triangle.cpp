#include <iostream>
using namespace std;

void generatePascalsTriangle(int pascal[][25], int n) 
{
    // First row
    for (int i = 0; i < n; i++) 
    {
        pascal[i][0] = 1;
    }
    // Rest of the triangle
    for (int i = 1; i < n; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
}

// Function to get the element at position (r, c) in Pascal's Triangle
int getElement(int pascal[][25], int r, int c) 
{
    if (c > r || c < 1 || r < 1) 
    {
        return 0; // Invalid position
    }
    return pascal[r - 1][c - 1];
}

// Function to print the nth row of Pascal's Triangle
void printNthRow(int pascal[][25], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << pascal[n - 1][i] << " ";
    }
    cout << endl;
}

// Function to print the first n rows of Pascal's Triangle
void printFirstNRows(int pascal[][25], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    const int MAX = 25;
    int pascal[MAX][MAX] = {0};
    int n = 5;
    int r = 5, c = 3;
    // Generate Pascal's Triangle up to MAX rows
    generatePascalsTriangle(pascal, n);
    // Variation 1 : Print the element at position (r, c)
    cout << "Element at position (" << r << ", " << c << ") is: " << getElement(pascal, r, c) << endl;
    // Variation 2 : Print the nth row
    cout << "Row " << n << " of Pascal's Triangle is: ";
    printNthRow(pascal, n);
    // Variation 3 : Print the first n rows
    cout << "First " << n << " rows of Pascal's Triangle are:" << endl;
    printFirstNRows(pascal, n);

    return 0;
}
