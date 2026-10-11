#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bitset<100'001> dp;
    dp[0] = true;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        dp |= dp << x;
    }

    int k = 0;
    for (int i = 1; i <= 100'001; i++) {
        if (dp[i]) k++;
    }
    cout << k << "\n";
    for (int i = 1; i <= 100'001; i++) {
        if (dp[i]) cout << i << " ";
    }

    return 0;
}