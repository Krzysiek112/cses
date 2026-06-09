#include <bits/stdc++.h>
using namespace std;

/*
Observations:
The count of numbers divisable by k in the range (1, k) can be counted by n / k

Approach: inclusion exclusion
for a given subset of primes given, calculate the product (set intersection), then substract/add from the result
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int k;

    cin >> n >> k;
    
    vector<long long> primes(k);
    for (int i = 0; i < k; i++) {
        long long a;
        cin >> a;

        primes[i] = a;
    }

    long long res = 0;
    for (int i = 1; i < (1 << k); i++) {
        long long d = 1;
        int items = 0;
        bool overflow = false;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                items++;
                if (d > n / primes[j]) {
                    overflow = true;
                    break;
                }

                d *= primes[j];
            }
        }

        if (overflow) continue;
        long long divisable = n / d;
        if (items % 2 == 1) {
            res += divisable;
        }
        else {
            res -= divisable;
        }
    }

    cout << res;
    return 0;
}