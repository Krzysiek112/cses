#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u = -1;
    int v = -1;
    int x = 0;
    Edge(int from = -1, int to = -1, int score = 0) {
        u = from;
        v = to;
        x = score;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> g(m);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        g[i] = Edge(a - 1, b - 1, x);
    }

    // Bellman-Ford
    vector<long long> dists(n, LLONG_MIN);
    dists[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (Edge e : g) {
            if (dists[e.u] != LLONG_MIN && dists[e.u] + e.x > dists[e.v]) {
                dists[e.v] = dists[e.u] + e.x;
            }
        }
    }

    // test for a positive score cycle
    for (int i = 0; i < n; i++) {
        for (const auto& e : g) {
            if (dists[e.u] > LLONG_MIN) {
                if (dists[e.u] == LLONG_MAX || dists[e.u] + e.x > dists[e.v]) {
                    dists[e.v] = LLONG_MAX; // Mark as infinitely reachable
                }
            }
        }
    }

    // If node n-1 is affected by a positive cycle reachable from 0
    if (dists[n - 1] == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << dists[n - 1] << "\n";
    }

    return 0;
}