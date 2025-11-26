#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mstSet(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first, wt = p.second;
            if (!mstSet[v] && wt < key[v]) {
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST edges:\n";
    int cost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}
