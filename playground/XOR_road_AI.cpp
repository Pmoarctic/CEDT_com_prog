#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint Set Union (DSU) for Kruskal's algorithm
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vector<tuple<int, int, int>> edges; // {weight, node1, node2}

    // Construct graph: calculate weights for all pairs of nodes
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = data[i] ^ data[j];
            edges.push_back({weight, i, j});
        }
    }

    // Sort edges by weight in descending order
    sort(edges.rbegin(), edges.rend());

    // Kruskal's algorithm for Maximum Spanning Tree
    DSU dsu(n);
    long long maxSpanTreeWeight = 0;
    for (auto &[weight, u, v] : edges) {
        if (dsu.unite(u, v)) {
            maxSpanTreeWeight += weight;
        }
    }

    cout << maxSpanTreeWeight << endl;
    return 0;
}
