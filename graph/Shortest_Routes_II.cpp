#include <bits/stdc++.h>
using namespace std;

/*
Observations:
Need to pre-process every single distance a - > b

Approach; Floyd-Warshall
Floyd Warshall is made for this problem

Apparently the graph isn't simple in this problem so only keep the shortest edges
*/

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dists(n, vector<long long>(n, LONG_LONG_MAX));
    for (int _ = 0; _ < m; _++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        dists[a][b] = min(dists[a][b], (long long)c);
        dists[b][a] = min(dists[b][a], (long long)c);
    }

    for (int u = 0; u < n; u++) {
        dists[u][u] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dists[u][k] == LONG_LONG_MAX || dists[k][v] == LONG_LONG_MAX) continue;

                dists[u][v] = min(dists[u][v], dists[u][k] + dists[k][v]);
            }
        }
    }

    for (int _ = 0; _ < q; _++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (dists[a][b] == LONG_LONG_MAX) {
            cout << -1;
        }
        else {
            cout << dists[a][b];
        }

        cout << "\n";
    }


    return 0;
}