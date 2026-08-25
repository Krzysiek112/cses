#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    constexpr int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        if (b == 0) {
            cout << 1 << "\n";
            continue;
        }
        
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b /= 2;
        }

        cout << res << "\n";
    }

    return 0;
}