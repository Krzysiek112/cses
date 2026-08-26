#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 5; i <= n; i += 5) {
        int num = i;
        while (num % 5 == 0) {
            num /= 5;
            res++;
        }
    }

    cout << res;
    return 0;
}