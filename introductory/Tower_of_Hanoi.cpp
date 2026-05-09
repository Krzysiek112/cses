#include <bits/stdc++.h>
using namespace std;

/*
Observations:
There is actually a strategy for optimally playing this game

Approach: divide and conquer
if n is even, we have to use the stack 2, then move the biggest peg to stack 3
otherwise, we can move it directly to the stack 3

we move n - 1 pegs to the stack depending on parity, then move the nth peg to the other

also the number of moves will always apparently be 2^n - 1
*/

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to);

    cout << from << " " << to << '\n';

    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);

    return 0;
}