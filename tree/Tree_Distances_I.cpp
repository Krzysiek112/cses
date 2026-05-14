#include <bits/stdc++.h>
using namespace std;

/*
Observation:
The maximum distance from root to any node is the tree's depth itself

The longest distance between any two points will always end at either end of the trees diameter

Approach: tree diameter
figure out both end points of the tree's diameneter

run bfs from both points
at every node record the distance from that point

run another traversal, this time record the anwser at every node
the anwser at every node will be max(dist_a[u], dist_b[u])
where dist_a[u] is the distance to node u from endpoint_a
and dist_b[u] is the distance to node u from endpoint_b
*/

int diameter_len = 0;
int endpoint_a = -1;
int endpoint_b = -1;
pair<int, int> diameter(int u, int last, const vector<vector<int>>& g) {

    int best_depth1 = 0;
    int best_depth2 = 0;
    int leaf1 = -1;
    int leaf2 = -1;
    if (g[u].size() == 1) leaf1 = u;

    for (const int& v : g[u]) {
        if (v == last) continue;

        pair<int, int> p = diameter(v, u, g);
        int d = p.first + 1;
        int l1 = p.second;

        if (d >= best_depth1) {
            best_depth2 = best_depth1;
            best_depth1 = d;

            leaf2 = leaf1;
            leaf1 = l1;
        } 
        else if (d > best_depth2) {
            best_depth2 = d;

            leaf2 = l1;
        }
    }
    if (best_depth1 + best_depth2 > diameter_len) {
        diameter_len = best_depth1 + best_depth2;

        endpoint_a = leaf1;
        endpoint_b = leaf2;
    }

    return {best_depth1, leaf1};
}
void dfs(int u, int last, const vector<vector<int>>& g, vector<int>& res, const vector<vector<int>>& dists) {
    res[u] = max(dists[u][0], dists[u][1]);
    for (const int& v : g[u]) {
        if (v == last) continue;

        dfs(v, u, g, res, dists);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    diameter(0, -1, g);

    queue<pair<int, int>> q;
    vector<vector<int>> dists(n, vector<int>(2, INT_MAX));

    q.push({endpoint_a, 0});
    q.push({endpoint_b, 1});

    dists[endpoint_a][0] = 0;
    dists[endpoint_b][1] = 0;

    int level = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            int u = q.front().first;
            int s = q.front().second;
            q.pop();

            for (const int& v : g[u]) {
                if (dists[v][s] > level) {
                    dists[v][s] = level;
                    q.push({v, s});
                }
            }
        }
        level++;
    }

    vector<int> res(n);
    dfs(0, -1, g, res, dists);

    for (const int& d : res) {
        cout << d << " ";
    }

    return 0;
}