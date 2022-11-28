#include <bits/stdc++.h>
using namespace std;

vector<int> bellmond_ford(int n, int source, vector<vector<int>> edges){
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    int u, v, w;
    for(int i = 0; i < n; i++){
        for(auto node : edges){
            u = node[0];
            v = node[1];
            w = node[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto node : edges){
            u = node[0];
            v = node[1];
            w = node[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                cout << "Negative cycle present" << endl;
                return {};
            }
        }
    }

    return dist;
}
int main()
{
    vector<vector<int>> edges = {{1,2,6}, {1,3,5}, {1,4,5}, {2,5,-1}, {3,2,-2}, {3,5,1}, {4,3,-2}, {4,6,-1}, {5,7,3}, {6,7,3}};
    vector<int> distance = bellmond_ford(7,1,edges);
    cout << "Distance = " << distance[7] << endl;

    return 0;
}