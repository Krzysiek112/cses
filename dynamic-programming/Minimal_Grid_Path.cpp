#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            grid[i][j] = c;
        }
    }

    vector<pair<int, int>> q;
    q.push_back({0, 0});
    string res = "";

    const int dirs[2][2] = {{1, 0}, {0, 1}};
    vector<vector<bool>> seen(n, vector<bool>(n));
    res.push_back(grid[0][0]);
    while (!q.empty()) {
        char min_char = CHAR_MAX;
        for (auto [r, c] : q) {
            for (int i = 0; i < 2; i++) {
                int dr = r + dirs[i][0];
                int dc = c + dirs[i][1];
                
                if (dr < n && dc < n) {
                    min_char = min(min_char, grid[dr][dc]);
                }
            }
        }

        if (min_char == CHAR_MAX) break;

        res += min_char;
        vector<pair<int, int>> nxt;
        for (auto [r, c] : q) {
            for (int i = 0; i < 2; i++) {
                int dr = r + dirs[i][0];
                int dc = c + dirs[i][1];
                
                if (dr < n && dc < n && grid[dr][dc] == min_char && !seen[dr][dc]) {
                    seen[dr][dc] = true;
                    nxt.push_back({dr, dc});
                }
            }
        }
        q = move(nxt);
    }

    cout << res;
    return 0;
}