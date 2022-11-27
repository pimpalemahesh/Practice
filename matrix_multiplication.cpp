#include <bits/stdc++.h>
using namespace std;

















// neive approch
// int main()
// {
//     vector<vector<int>> matrix1 = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}};
//     vector<vector<int>> matrix2 = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}};

//     int n = matrix1.size();
//     vector<vector<int>> matrix3(n, vector<int>(n, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = 0; k < n; k++)
//             {
//                 matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << matrix3[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }