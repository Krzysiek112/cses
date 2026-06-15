#include <bits/stdc++.h>
using namespace std;

/*
Observations:
The number of derangements can be calculated with inclusion enclusion

Approach: inclusion exclusion + modular inversion
You can't divide and preserve the modular property, instead you have to use modular inversion

modular inversion: a = a^(mod - 2)
*/

const int MOD = 1e9 + 7;
long long modPow(long long a, long long e) {
    long long res = 1;

    while (e > 0) {
        if (e % 2 == 1) {
            res = (res * a) % MOD;
            e--;
        }

        a = (a * a) % MOD;
        e /= 2;
    }

    return res;
}

long long modInverse(long long a) {
    return modPow(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<long long> factorials(n + 1);
    factorials[0] = 1;
    for (long long i = 1; i <= n; i++) {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }

    long long res = 0;
    for (int k = 0; k <= n; k++) {
        long long choose = factorials[n] * modInverse(factorials[k]) % MOD * modInverse(factorials[n - k]) % MOD;
        long long permutations = (factorials[n - k] * choose) % MOD;
        if (k % 2 == 0) {
            res = (res + permutations) % MOD;
        }
        else {
            res = (res - permutations + MOD) % MOD;
        }
    }

    cout << res;
    return 0;
}