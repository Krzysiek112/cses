#include <bits/stdc++.h>
using namespace std;

/*
Observations:
The problem is finding the shortest path from node a to every other node

Approach: Dijkstra's
This makes for a classic Dijkstra's problem
*/

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int _ = 0; _ < m; _++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].push_back({v - 1, w});
    }

    vector<unsigned long long> dists(n, ULLONG_MAX);
    dists[0] = 0;

    priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        unsigned long long w1 = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dists[u] < w1) continue;
        for (auto& [v, w2] : g[u]) {
            unsigned long long w = w1 + w2;
            if (dists[v] > w) {
                dists[v] = w;
                pq.push({w, v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dists[i] << " ";
    }

    return 0;
}