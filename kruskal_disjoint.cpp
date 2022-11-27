#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        // At start every node will be parent of itself and it's rank will be 0.
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    // recursively check untill parent of node is itself
    if(parent[node] == node){
        return node;
    } 
    // return findParent(parent, parent[node]);        This will calculate parent recursively until it gets value at each time hence time consuming
    return parent[node] = findParent(parent, parent[node]);       // This will assign value of parent node directly to given node.
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[v]++;
    }
}  

int minimumSpanningTree(vector<vector<int>> edges, int n){
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n), rank(n);
    makeSet(parent, rank, n);
    int u, v, wt, minWeight = 0;
    for(auto node : edges){
        u = findParent(parent, node[0]);
        v = findParent(parent, node[1]);
        wt = node[2];
        if(u != v){
            minWeight += wt;
            unionSet(u, v, parent, rank);
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