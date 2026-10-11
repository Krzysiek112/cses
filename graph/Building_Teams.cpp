#include <bits/stdc++.h>
using namespace std;

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

    queue<int> q;
    vector<int> color(n);

    for (int i = 0; i < n; i++) {
        if (color[i] != 0) continue;

        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (color[v] == color[u]) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
                if (color[v] == 0) q.push(v);

                if (color[u] == 1) color[v] = 2;
                else color[v] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
    return 0;
}