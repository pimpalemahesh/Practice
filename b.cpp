#include <bits/stdc++.h>
using namespace std;

inline bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    } 
    return parent[node] = findParent(parent, parent[node]); 
}

void unionSet(int u, int v, vector<int> &parent){
    parent[u] = v;
}  

int minimumSpanningTree(vector<vector<int>> edges, int n){
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    int u, v, minWeight = 0;
    for(auto node : edges){
        u = findParent(parent, node[0]);
        v = findParent(parent, node[1]);
        if(u != v){
            minWeight += node[2];
            unionSet(u, v, parent);
        }
    }

    return minWeight;
}
int main()
{
    vector<vector<int>> edges = {{0, 1, 15}, {0, 2, 10}, {0, 3, 19}, {1, 3, 7}, {1, 4, 17}, {2, 3, 16}, {2, 5, 14}
    , {3, 4, 12}, {3, 5, 6}, {3, 6, 3}, {4, 7, 13}, {4, 6, 20}, {5, 6, 9}, {5, 8, 5}, {6, 7, 4}, {6, 9, 11}, {6, 8, 1}, {7, 9, 2}, {8, 9, 18}};
    cout << "Minimum Weight = " << minimumSpanningTree(edges, edges.size()) << endl;
    return 0;
}