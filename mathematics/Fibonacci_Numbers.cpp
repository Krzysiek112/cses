#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;
class Matrix {
public:
    long long mat[2][2] = {{-1, -1}, {-1, -1}};
    Matrix(int aa, int ab, int ba, int bb) {
        mat[0][0] = aa;
        mat[0][1] = ab;
        mat[1][0] = ba;
        mat[1][1] = bb;
    }

    void multiply(Matrix b) {
        long long c[2][2] = {{0, 0}, {0, 0}};
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    c[i][j] += (mat[i][k] * b.mat[k][j]) % mod;
                }
            }
        }

        swap(mat, c);
    }
};
/*
matrix exponentiation is a technique used to speed up
constant space bottom up dp. In this example we can use this
technique to speed up fibbonacci numbers from O(n) to O(log n)
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    if (n == 0 || n == 1) {
        cout << n;
        return 0;
    }
    n--;

    Matrix res(1, 0, 1, 0);
    Matrix fib(1, 1, 1, 0);
    while (n > 0) {
        if (n % 2 == 1) {
            res.multiply(fib);
        }

        fib.multiply(fib);
        n /= 2;
    }

    cout << res.mat[0][0] % mod;
    return 0;
}