#include <bits/stdc++.h>
using namespace std;

/*
Observations:
Its always the most optimal to put a new cube on the tower with the smallest possible top
that allows to put the new cube

Approach: BST
We store the current towers in a multiset

each node in the BST is an integer representing the top cube at some tower

if the new cube is smaller than all integers in the tree, then create a new tower with
that new cube as its base

otherwise, update the first integer thats lower than cube (cube < top)

the anwser for the problem will be the size of the multiset
*/

int main() {
    int n;
    cin >> n;

    multiset<int> towers;
    for (int _ = 0; _ < n; _++) {
        int cube;
        cin >> cube;

        auto it = towers.upper_bound(cube);
        if (it == towers.end()) {
            towers.insert(cube);
        }
        else {
            towers.insert(it, cube);
            towers.erase(it);
        }
    }

    cout << towers.size();
    return 0;
}