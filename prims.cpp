// Prim's Algorithm in C++

#include <bits/stdc++.h>
using namespace std;

#define V 10

map<int, char> mp = {{0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}, {6, 'G'}, {7, 'H'}, {8, 'I'}, {9, 'J'}};
int G[V][V] = {
    {0, 15, 10, 19, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 7, 17, 0, 0, 0, 0, 0},
    {10, 0, 0, 16, 0, 14, 0, 0, 0, 0},
    {19, 7, 16, 0, 12, 6, 3, 0, 0, 0},
    {0, 17, 0, 12, 0, 0, 20, 13, 0, 0},
    {0, 0, 14, 6, 0, 0, 9, 0, 5, 0},
    {0, 0, 0, 3, 20, 9, 0, 4, 1, 11},
    {0, 0, 0, 0, 13, 0, 4, 0, 0, 2},
    {0, 0, 0, 0, 0, 5, 1, 0, 0, 18},
    {0, 0, 0, 0, 0, 0, 11, 2, 18, 0},
};

int main()
{
    int x, y, no_edge = 0;
    int selected[V];

    memset(selected, false, sizeof(selected));

    selected[0] = true;
    cout << "Edge : Weight" << endl;
    while (no_edge < V - 1)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << mp[x] << " - " << mp[y] << " :  " << G[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}