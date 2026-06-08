#include <bits/stdc++.h>
using namespace std;

/*
Observations:
if two numbers share the same prime factor, then they won't be coprime
otherwise if two numbers possess distinct prime factors, then they will be coprime

its impossible to count all pairs manually due to the constraints

Approach: inclusion exclusion

Its faster to calculate how many pairs aren't co-prime

steps:
1. calculate the frequency array, where freq[i] = number of elements of value i in nums
2. calculate the prime_factors array, where prime_factors[i] = vector of prime factors of number i
3. calculate divisable array, where divisable[i] = number of elements in nums which are divisable by i
4. use inclusion exclusion to calculate how many elements aren't coprime with each other

by definition, inclusion exlusion is x = |A| + |B| + |C| - |A ∩ B| - |B ∩ C| - |A ∩ C| + |A ∩ B ∩ C|

the number of elements in a subset tells us if to add or substract the intersection of sets
odd -> add
even -> substract

The subsets A, B, C are divisable[A/B/C]
Any set intersection wil be divisable[product of subset]

example: set(2, 3)
inclusion exclusion: x = |2| + |3| - |2 ∩ 3|

notice how the elements divisable by 6 (product of 2 and 3) are doubly counted, if we only add divisables of 2 and 3
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

    vector<int> freq(max_element + 1);
    for (const int& num : nums) {
        freq[num]++;
    }

    vector<vector<int>> prime_factors(max_element + 1);
    vector<bool> is_prime(max_element + 1, true);
    
    for (int i = 2; i <= max_element; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= max_element; j += i) {
                is_prime[j] = false;
                prime_factors[j].push_back(i); // i is a prime factor of j
            }
        }
    }

    // divisable[i] = number of elements in nums divisible by i
    vector<long long> divisable(max_element + 1, 0);
    for (int i = 1; i <= max_element; i++) {
        for (int j = i; j <= max_element; j += i) {
            divisable[i] += freq[j];
        }
    }

    long long res = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] == 0) continue;
        int k = prime_factors[i].size();
        int subsets = (1 << k);
        long long bad_elements = 0;

        // enumerate the subsets
        for (int j = 1; j < subsets; j++) {
            long long divisor = 1;
            int items = 0;

            for (int u = 0; u < k; u++) {
                int bitmask = (1 << u);
                if (j & bitmask) {
                    items++;
                    divisor *= prime_factors[i][u];
                }
            }

            if (items % 2 == 1) {
                bad_elements += divisable[divisor];
            }
            else {
                bad_elements -= divisable[divisor];
            }
        }
        
        // exclude self
        if (i > 1) {
            bad_elements--;
        }

        res += bad_elements * freq[i];
    }

    res /= 2; // everything got doubly counted
    long long total_pairs = (long long)n * (n - 1) / 2;
    long long coprime_pairs = total_pairs - res;

    cout << coprime_pairs;
    
    return 0;
}