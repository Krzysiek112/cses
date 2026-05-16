#include <bits/stdc++.h>
using namespace std;

/*
Observations:
-

Approach: Sweep line
store events for every single interval

when sweeping an interval: adjust the current amount of customers

get the maximum at every step
*/

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    events.reserve(n);
    for (int _ = 0; _ < n; _++) {
        int a, b;
        cin >> a >> b;

        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());
    int res = 0;
    int cur = 0;
    for (auto& [i, t] : events) {
        cur += t;
        res = max(res, cur);
    }
    cout << res;
}