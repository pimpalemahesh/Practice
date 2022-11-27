#include <bits/stdc++.h>
using namespace std;

vector<int> dj(vector<vector<int>> &vt, int nodes, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    int u, v, w;
    for (auto i : vt)
    {
        u = i[0];
        v = i[1];
        w = i[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(nodes, INT_MAX);

    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto node = *(st.begin());
        int node_distance = node.first;
        int curr_node = node.second;
        st.erase(node);

        for (auto neighbor_node : adj[curr_node])
        {
            if (node_distance + neighbor_node.second < dist[neighbor_node.first])
            {
                auto original_node = st.find({dist[neighbor_node.first], neighbor_node.first});
                if (original_node != st.end())
                {
                    st.erase({original_node});
                }
                dist[neighbor_node.first] = node_distance + neighbor_node.second;
                st.insert({dist[neighbor_node.first], neighbor_node.first});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 15}, {0, 2, 10}, {0, 3, 19}, {1, 3, 7}, {1, 4, 17}, {2, 3, 16}, {2, 5, 14}, {3, 4, 12}, {3, 5, 6}, {3, 6, 3}, {4, 7, 13}, {4, 6, 20}, {5, 6, 9}, {5, 8, 5}, {6, 7, 4}, {6, 9, 11}, {6, 8, 1}, {7, 9, 2}, {8, 9, 18}};

    vector<int> distance = dj(edges, 10, 1);
    cout << "Node : Cost" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << char(i + 'A') << " : " << distance[i] << endl;
    }
    return 0;
}