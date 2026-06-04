#include <bits/stdc++.h>
using namespace std;

/*
Observation:
Every time a deletion is performed, every index past the removed one is decremented by 1

Approach: Segment tree + Lazy propagation
Every single node holds {possible val (only on leaf nodes), left range, right range}
where left range and right range represent the range [l, r] of the child indicies that exist

on removal, binary search to the deleted position
then use lazy propagation to decrement the positions after
*/

// Custom struct to replace std::tuple<int, int, int>
struct Node {
    int val;
    int l_range;
    int r_range;
};

// helper function - lazily updates the range at some node
void push(vector<Node>& seg, int l, int r, int i, vector<int>& lazy) {
    if (lazy[i] != 0) {
        if (seg[i].l_range != -1) {
            seg[i].l_range += lazy[i];
        }
        
        if (seg[i].r_range != -1) {
            seg[i].r_range += lazy[i];
        }
        
        if (l != r) {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

// builds the tree
void build(vector<Node>& seg, int l, int r, int i, vector<int>& nums, vector<int>& lazy) {
    if (l == r) {
        seg[i] = {nums[l], l, l};
        return;
    }

    int m = l + (r - l) / 2;
    build(seg, l, m, i * 2, nums, lazy);
    build(seg, m + 1, r, i * 2 + 1, nums, lazy);

    int left_range = seg[i * 2].l_range;
    int right_range = seg[i * 2 + 1].r_range;

    seg[i] = {-1, left_range, right_range};
}

// returns the deleted element
int del(vector<Node>& seg, int q, int l, int r, int i, vector<int>& lazy) {
    push(seg, l, r, i, lazy);
    if (q < seg[i].l_range || q > seg[i].r_range) return -1;
    if (l == r) {
        int res = seg[i].val;
        seg[i] = {-1, -1, -1};
        return res;
    }

    int m = l + (r - l) / 2;

    int res = del(seg, q, l, m, 2 * i, lazy);
    if (res == -1) res = del(seg, q, m + 1, r, 2 * i + 1, lazy);

    // Recalculate parent ranges after a deletion shifts things
    push(seg, l, m, 2 * i, lazy);
    push(seg, m + 1, r, 2 * i + 1, lazy);
    auto& L = seg[2 * i];
    auto& R = seg[2 * i + 1];

    if (L.l_range == -1) seg[i].l_range = R.l_range;
    else if (R.l_range == -1) seg[i].l_range = L.l_range;
    else seg[i].l_range = min(L.l_range, R.l_range);

    if (L.r_range == -1) seg[i].r_range = R.r_range;
    else if (R.r_range == -1) seg[i].r_range = L.r_range;
    else seg[i].r_range = max(L.r_range, R.r_range);

    return res;
}

// updates the range [ql, qr] in the tree
void update(vector<Node>& seg, int l, int r, int ql, int qr, int i, vector<int>& lazy) {
    push(seg, l, r, i, lazy);
    if (seg[i].l_range == -1 || seg[i].r_range == -1) return; // Guard against dead nodes
    if (seg[i].r_range < ql || seg[i].l_range > qr) return;
    if (seg[i].l_range >= ql && seg[i].r_range <= qr) {
        lazy[i]--;
        push(seg, l, r, i, lazy);
        return;
    }

    int m = l + (r - l) / 2;
    update(seg, l, m, ql, qr, 2 * i, lazy);
    update(seg, m + 1, r, ql, qr, 2 * i + 1, lazy);

    push(seg, l, m, 2 * i, lazy);
    push(seg, m + 1, r, 2 * i + 1, lazy);
    auto& L = seg[2 * i];
    auto& R = seg[2 * i + 1];

    if (L.l_range == -1) {
        seg[i].l_range = R.l_range;
    }
    else if (R.l_range == -1) {
        seg[i].l_range = L.l_range;
    }
    else {
        seg[i].l_range = min(L.l_range, R.l_range);
    }

    if (L.r_range == -1) {
        seg[i].r_range = R.r_range;
    }
    else if (R.r_range == -1) {
        seg[i].r_range = L.r_range;
    }
    else {
        seg[i].r_range = max(L.r_range, R.r_range);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<Node> seg(4 * n);
    vector<int> lazy(4 * n, 0);
    build(seg, 0, n - 1, 1, nums, lazy);

    for (int k = 0; k < n; k++) {
        int j;
        cin >> j;

        int res = del(seg, j - 1, 0, n - 1, 1, lazy);
        cout << res << (k == n - 1 ? "" : " ");

        update(seg, 0, n - 1, j, n - k - 1, 1, lazy);
    }

    return 0;
}