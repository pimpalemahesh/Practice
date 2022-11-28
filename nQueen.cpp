#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{

    // checking if queen exist in same column above this position.
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }

    // checking if queen present diagonally to the left above this position.
    int row = x, col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // checking if queen present diagonally to the right above this position.
    row = x, col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n)
{

    if (x >= n)
    {
        return true;
    }

    // if queen is not present in current row and condition is safe then insert queen at this position.
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            // call recursively for next row.
            // if function returns true then position of queens in all above rows are right and we can place
            // queen in corresponding row else we need to backtrack and find another way of arranging all queens.
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            // set value 0 if backtracking fails.
            arr[x][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int ** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nSolution doesn't exist" << endl;
    }

    return 0;
}