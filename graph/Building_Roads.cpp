#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>>& g, vector<bool>& visited) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, g, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> comps;
    vector<bool> visited(n);
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            comps.push_back(u + 1);
            dfs(u, g, visited);
        }
    }

    cout << comps.size() - 1 << "\n";
    for (int i = 1; i < comps.size(); i++) {
        cout << comps[i - 1] << " " << comps[i] << "\n";
    }

    return 0;
}