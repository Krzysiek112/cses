#include <bits/stdc++.h>
using namespace std;

/*
Observations:
There will never be a solution for n < 4 that isnt a single element
with only n = 4 having a different solution

Approach: greedy
always choose the closest integer that isnt consequtive, loop
around if we exceed n
(starting from even numbers, because of n = 4 exception)
*/
int main() {
    int n;
    cin >> n;

    if (n < 4) {
        if (n == 1) cout << "1";
        else cout << "NO SOLUTION";

        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i;
        if (i + 2 <= n) cout << " ";
    }

    return 0;
}