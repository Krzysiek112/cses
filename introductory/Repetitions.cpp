#include <bits/stdc++.h>
using namespace std;

/*
Observations:
-
Approach: simple counting
simply count the consequtive characters
*/

int main() {
    string s;
    cin >> s;

    const int n = s.length();

    int res = 1;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (i != 0 && s[i] == s[i - 1]) {
            cur++;
            res = max(res, cur);
        }
        else {
            cur = 1;
        }
    }
    cout << res;

    return 0;
}