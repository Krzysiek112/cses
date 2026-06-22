#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x, y;
        cin >> x >> y;
 
        if (y > x) {
            if (y % 2 == 1) {
                cout << y * y - x + 1;
            }
            else {
                cout << (y - 1) * (y - 1) + x;
            }
        }
        else {
            if (x % 2 == 0) {
                cout << x * x - y + 1;
            }
            else {
                cout << (x - 1) * (x - 1) + y;
            }
        }
        cout << "\n";
    }

    return 0;
}