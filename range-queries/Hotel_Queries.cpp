#include <bits/stdc++.h>
using namespace std;

int give_rooms(int l, int r, int i, int g, vector<int>& hotels, vector<int>& seg) {
    if (seg[i] < g) {
        return -1;
    }
    if (l == r) {
        seg[i] -= g;
        return l;
    }

    int m = l + (r - l) / 2;

    int idx = give_rooms(l, m, 2 * i, g, hotels, seg);
    if (idx != -1) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        return idx;
    }

    idx = give_rooms(m + 1, r, 2 * i + 1, g, hotels, seg);
    if (idx != -1) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        return idx;
    }

    return -1;
}

void build(int l, int r, int i, vector<int>& hotels, vector<int>& seg) {
    if (l == r) {
        seg[i] = hotels[l];
        return;
    }

    int m = l + (r - l) / 2;
    build(l, m, 2 * i, hotels, seg);
    build(m + 1, r, 2 * i + 1, hotels, seg);

    seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<int> hotels(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        
        hotels[i] = h;
    }

    vector<int> seg(4 * n);
    build(0, n - 1, 1, hotels, seg);

    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        
        int res = give_rooms(0, n - 1, 1, r, hotels, seg);
        cout << res + 1 << " ";
    }

    return 0;
}