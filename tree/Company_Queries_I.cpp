#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    constexpr int LOG = 20;

    // parent[i][k] = parent of the node i 2^k levels up
    vector<vector<int>> parent(n + 2, vector<int>(LOG, -1));
    for (int i = 2; i <= n; i++) {
        int node;
        cin >> node;

        parent[i][0] = node;
    }

    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i <= n; i++) {
            if (parent[i][k - 1] != -1) {
                parent[i][k] = parent[parent[i][k - 1]][k - 1];
            }
        }
    }

    for (int _ = 0; _ < q; _++) {
        int x, k;
        cin >> x >> k;
    
        for (int i = 0; (1 << i) <= k; i++) {
            if (k & (1 << i)) {
                x = parent[x][i];
                if (x == -1) break;
            }
        }
        cout << x << "\n";
    }

    return 0;
}