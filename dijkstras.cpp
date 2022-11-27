#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(vector<vector<int>> &vec, int vertices, int edges, int source){
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices, INT_MAX);

    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while(!st.empty()){
        // fetch first record from set.
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // remove record.
        st.erase(st.begin());

        // traverse on neighbour
        for(auto neighbor : adj[topNode]){
            if(nodeDistance + neighbor.second < dist[neighbor.first]){
                // if another record found with same distance then remove it.
                auto anotherRecord = st.find(make_pair(dist[neighbor.first], neighbor.first));
                if(anotherRecord != st.end()){
                    st.erase(anotherRecord);
                }

                // update distance.
                dist[neighbor.first] = nodeDistance + neighbor.second;
                
                // push record in set.
                st.insert(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> edges = {{0, 1, 15}, {0, 2, 10}, {0, 3, 19}, {1, 3, 7}, {1, 4, 17}, {2, 3, 16}, {2, 5, 14}
    , {3, 4, 12}, {3, 5, 6}, {3, 6, 3}, {4, 7, 13}, {4, 6, 20}, {5, 6, 9}, {5, 8, 5}, {6, 7, 4}, {6, 9, 11}, {6, 8, 1}, {7, 9, 2}, {8, 9, 18}};

    vector<int> distance = dijkstras(edges, 10, edges.size(), 0);
    cout << "Node : Cost" << endl;
    for(int i = 0; i < 10; i++){
        cout << char(i+'A') << " : " << distance[i] << endl;
    }
    return 0;
}