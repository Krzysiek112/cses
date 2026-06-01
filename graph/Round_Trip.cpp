#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> comp_size;

/*
Observations:
The problem is asking to find a cycle

A cycle will always contain 3 nodes, 
because that is the minimum number of nodes to form a cycle in a simple graph

Approach: Union-find + backtracking
since the goal is to find a cycle and re-create it, its easy to determine it with union-find

After finding the cycle, launch a dfs from the edge creating the cycle untill reaching the starter node
(idk why i didin't think that reaching any visited node will be sufficient)
*/

int find(int a) {
    int root = a;
    while (root != parent[root]) {
        root = parent[root];
    }
    while (a != parent[a]) {
        int nxt = parent[a];
        parent[a] = root;
        a = nxt;
    }
    return root;
}
void join(int x, int y) {
    if (x == y) return;
    if (comp_size[x] < comp_size[y]) swap(x, y);

    parent[y] = x;
    comp_size[x] += comp_size[y];
}

bool dfs(int u, int last, vector<int>& res, vector<vector<int>>& g, vector<bool>& visited, int goal) {
    if (u == goal) return true;

    visited[u] = true;
    res.push_back(u + 1);
    for (const int& v : g[u]) {
        if (v == last || visited[v]) continue;

        if (dfs(v, u, res, g, visited, goal)) return true;
    }
    visited[u] = false;
    res.pop_back();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent = vector<int>(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    comp_size = vector<int>(n, 1);

    vector<vector<int>> g(n);

    pair<int, int> saved_edge = {-1, -1};
    bool found_cycle = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (!found_cycle) {
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }

        int x = find(a - 1);
        int y = find(b - 1);
        if (x == y && !found_cycle) {
            saved_edge = {a, b};
            found_cycle = true;
        }
        join(x, y);
    }
    if (!found_cycle) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> res = {saved_edge.first};
    vector<bool> visited(n);
    dfs(saved_edge.second - 1, saved_edge.first - 1, res, g, visited, saved_edge.first - 1);

    cout << res.size() + 1 << "\n";
    for (const int& city : res) {
        cout << city << " ";
    }
    cout << saved_edge.first;

    return 0;
}