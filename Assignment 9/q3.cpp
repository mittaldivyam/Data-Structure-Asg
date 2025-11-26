#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    DSU dsu(V);
    vector<vector<int>> mst;
    int mstCost = 0;

    for (auto &e : edges) {
        if (dsu.find(e[0]) != dsu.find(e[1])) {
            dsu.unite(e[0], e[1]);
            mst.push_back(e);
            mstCost += e[2];
        }
    }

    cout << "Kruskal MST edges:\n";
    for (auto &e : mst) cout << e[0] << " - " << e[1] << " : " << e[2] << endl;
    cout << "Total Cost = " << mstCost << endl;
}
