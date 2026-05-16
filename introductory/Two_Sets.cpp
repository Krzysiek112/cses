#include <bits/stdc++.h>
using namespace std;

/*
Observation:
You can't divide properly if the sum isn't divisable by 2

if we know some numbers sum up to n // 2, then the other half will also sum up to n // 2

Approach: Greedy
Always choose the highiest available number less than or equal to the remaining target
*/

int main() {
    unsigned long long n;
    cin >> n;

    unsigned long long s = 0;
    for (unsigned long long i = 1; i <= n; i++) {
        s += i;
    }

    if (s % 2 != 0) {
        cout << "NO";
        return 0;
    }

    s /= 2;
    vector<bool> used(n + 1);
    int total_used = 0;
    int i = min(s, n);
    while (s > 0) {
        if (i <= s) {
            s -= i;
            used[i] = true;
            total_used++;
        }
        i--;
    }
    cout << "YES" << "\n";

    cout << total_used << "\n";
    for (unsigned long long i = 1; i <= n; i++) {
        if (used[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << n - total_used << "\n";
    for (unsigned long long i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << i << " ";
        }
    }

    return 0;
}