#include <bits/stdc++.h>
using namespace std;

/*
Observations:
if two numbers share the same prime factor, then they won't be coprime
otherwise if two numbers possess distinct prime factors, then they will be coprime

its impossible to count all pairs manually due to the constraints

Approach: Sieve of Eratosthenes + mobius function
lets compute all primes in the range of maximum element + the values of mobius

mobius will filter out duplicate coprime pairs that feature two of the same factors, multiple times

use the combinatorics formula to count the number of pairs divisable by i
*/

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    int max_element = -1;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        nums[i] = num;
        max_element = max(max_element, num);
    }

    vector<bool> sieve(max_element + 1, true);
    vector<int> mobius(max_element + 1, 1);
    for (int i = 2; i <= max_element; i++) {
        if (!sieve[i]) continue;

        for (int j = i; j <= max_element; j += i) {
            sieve[j] = false;
            mobius[j] *= -1;
        }

        long long sq = 1LL * i * i;
        if (sq <= max_element) {
            for (long long j = sq; j <= max_element; j += sq) {
                mobius[j] = 0;
            }
        }
    }
    
    vector<int> freq(max_element + 1);
    for (const int& num : nums) {
        freq[num]++;
    }

    long long res = 0;
    for (int i = 1; i <= max_element; i++) {
        int count = 0;

        for (int j = i; j <= max_element; j += i) {
            count += freq[j];
        }

        res += 1LL * mobius[i] * count * (count - 1) / 2;
    }

    cout << res;
    return 0;
}