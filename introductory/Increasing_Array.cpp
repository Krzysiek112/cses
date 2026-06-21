#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int prev = -1;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x >= prev) {
            prev = x;
        }
        else {
            res += prev - x;
        }
    }

    cout << res;
    return 0;
}