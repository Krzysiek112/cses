#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int d, vector<vector<int>>& g, vector<int>& depth) {
    depth[u] = d;
    for (int v : g[u]) {
        dfs(v, d + 1, g, depth);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    constexpr int LOG = 20;

    vector<vector<int>> parent(n + 1, vector<int>(LOG + 1, -1));
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;

        parent[i][0] = e;
        g[e].push_back(i);
    }

    for (int k = 1; k <= LOG; k++) {
        for (int u = 0; u <= n; u++) {
            if (parent[u][k - 1] != -1) {
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
            }
        }
    }
    vector<int> depth(n + 1, -1);
    dfs(1, 0, g, depth);

    for (int _ = 0; _ < q; _++) {
        int a, b;
        cin >> a >> b;

        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; (1 << i) <= diff; i++) {
            if (diff & (1 << i)) {
                a = parent[a][i];
            }
        }

        if (a == b) {
            cout << a << "\n";
            continue;
        }
        
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        cout << parent[a][0] << "\n";
    }

    return 0;
}