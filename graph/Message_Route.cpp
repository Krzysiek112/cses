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
    int dist = 0;
    int res = -1;
    queue<int> q;
    q.push(0);
    vector<int> seen(n);
    seen[0] = true;
    vector<int> breadcrumbs(n, -1);
    while (!q.empty()) {
        dist++;
        const int s = q.size();
        for (int i = 0; i < s; i++) {
            int u = q.front();
            q.pop();
            
            for (int v : g[u]) {
                if (!seen[v]) {
                    if (v == n - 1) res = dist + 1;
                    seen[v] = true;
                    breadcrumbs[v] = u;

                    q.push(v);
                }
            }
        }
    }
    if (res == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << res << "\n";
    int u = n - 1;
    vector<int> route;
    while (u > 0) {
        route.push_back(u + 1);
        u = breadcrumbs[u];
    }
    
    cout << 1 << " ";
    for (int u = route.size() - 1; u >= 0; u--) {
        cout << route[u] << " ";
    } 

    return 0;
}