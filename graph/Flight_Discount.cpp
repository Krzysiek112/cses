#include <bits/stdc++.h>
using namespace std;

/*
Observations:
the discount is always best used for the most weighted edge in a path

Approach: shortest path + states
Let's use Dijkstras and states to track the minimum price

g[u] holds pairs (v, w) where v is the connected city to u and w is the flight's
price

the pq holds pairs (w, u)

dists[u][0] holds the min cost without applied discount to node u
dists[u][1] holds the min cost with discount to node u

also the sum of weights might overflow so we store long long instead of ints
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

    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<tuple<long long, int, bool>>> pq;
    pq.push({0, 0, false});

    vector<vector<long long>> dists(n, vector<long long>(2, LONG_LONG_MAX));
    dists[0][0] = 0;

    while (!pq.empty()) {
        long long w1 = get<0>(pq.top());
        int u = get<1>(pq.top());
        bool s = get<2>(pq.top());

        pq.pop();
        if (w1 > dists[u][s]) continue;
        for (auto& [v, w2] : g[u]) {
            if (s) {
                if (dists[v][1] > w1 + w2) {
                    dists[v][1] = w1 + w2;
                    pq.push({w1 + w2, v, true});
                }
            }
            else {
                if (dists[v][0] > w1 + w2) {
                    dists[v][0] = w1 + w2;
                    pq.push({w1 + w2, v, false});
                }

                if (dists[v][1] > w1 + w2 / 2) {
                    dists[v][1] = w1 + w2 / 2;
                    pq.push({w1 + w2 / 2, v, true});
                }
            }
        }
    }

    cout << dists[n - 1][1];
    return 0;
}