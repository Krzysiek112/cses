#include <bits/stdc++.h>
using namespace std;

int n;
int m;
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int r, int c, vector<vector<char>>& grid) {
    grid[r][c] = 'T';
    for (auto [x, y] : dirs) {
        int dr = r + x;
        int dc = c + y;

        if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] != '#' && grid[dr][dc] != 'T') {
            dfs(dr, dc, grid);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char x;
            cin >> x;

            grid[r][c] = x;
        }
    }

    int k = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == '#' || grid[r][c] == 'T') continue;

            k++;
            dfs(r, c, grid);
        }
    }

    cout << k;
    return 0;
}