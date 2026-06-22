#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MOD = 1e9 + 7;

    int n;
    cin >> n;

    long long res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 2) % MOD;
    }

    cout << res;

    return 0;
}