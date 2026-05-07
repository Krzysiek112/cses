#include <bits/stdc++.h>
using namespace std;

/*
Observations:
constraints of h, t are too high to use prefix arrays

Approach: Sorting
We have to use a sorted data structure that supports deletions and lookups in O(log n)
*/

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> prices;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        prices[h]++;
    }

    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; i++) {
        auto it = prices.upper_bound(queries[i]);
        if (it == prices.begin()) {
            cout << -1;
            if (i != m - 1) cout << "\n";
            continue;
        }

        it--;

        cout << it->first;
        prices[it->first]--;
        if (prices[it->first] <= 0) prices.erase(it->first);

        if (i != m - 1) cout << "\n";
    }

    return 0;
}