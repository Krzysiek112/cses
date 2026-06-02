#include <bits/stdc++.h>
using namespace std;

/*
Observations:
the problem is 0/1 Knapsack

Approach: Dynamic programming

state: dp[i] = most number of pages for cost i
recurrence: dp[i] = max(dp[i], dp[j - h] + s)

keep in mind that to 1D-ify this problem you have to enumerate the capacity backwards
*/

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> books(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;

        books[i][0] = w;
    }
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        books[i][1] = val;
    }

    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++) {
        int h = books[i][0];
        int s = books[i][1];

        for (int j = x; j >= h; j--) {
            dp[j] = max(dp[j], dp[j - h] + s);
        }
    }

    cout << dp[x];
}