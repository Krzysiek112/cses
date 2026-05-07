#include <bits/stdc++.h>
using namespace std;

/*
Observations:
every number is unique

Approach: indexing
Collect every number and set vec[num] = true
the only i where vec[i] is false is the anwser
*/

int main() {
    int n;
    cin >> n;

    vector<bool> is_available(n);
    for (int _ = 0; _ < n - 1; _++) {
        int num;
        cin >> num;

        is_available[num - 1] = true;
    }
    
    for (int i = 0; i < n; i++) {
        if (!is_available[i]) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}