#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    int start_r = -1;
    int start_c = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            grid[i][j] = c;
            if (c == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            if (c == 'A') {
                start_r = i;
                start_c = j;
            }
        }
    }
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int d = 0;
    while (!q.empty()) {
        d++;
        const int s = q.size();
        for (int i = 0; i < s; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto [x, y] : dirs) {
                int dr = r + x;
                int dc = c + y;

                if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] != '#' && dist[dr][dc] > d) {
                    dist[dr][dc] = d;
                    q.push({dr, dc});
                }
            }
        }
    }

    vector<vector<char>> breadcrumbs(n, vector<char>(m, '#'));
    q.push({start_r, start_c});
    d = 0;
    int exit_r = -1;
    int exit_c = -1;
    while (!q.empty()) {
        d++;
        const int s = q.size();
        for (int i = 0; i < s; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto [x, y] : dirs) {
                int dr = r + x;
                int dc = c + y;
                if (dr < 0 || dr >= n || dc < 0 || dc >= m) {
                    if (exit_r == -1) {
                        exit_r = r;
                        exit_c = c;
                    }

                    continue;
                }
                if (breadcrumbs[dr][dc] != '#') continue;
                if (grid[dr][dc] != '#' && dist[dr][dc] > d) {
                    q.push({dr, dc});
                    if (x == -1) {
                        breadcrumbs[dr][dc] = 'D';
                    } else if (x == 1) {
                        breadcrumbs[dr][dc] = 'U';
                    } else if (y == -1) {
                        breadcrumbs[dr][dc] = 'R';
                    } else {
                        breadcrumbs[dr][dc] = 'L';
                    }
                }
            }
        }
    }

    if (exit_r == -1) {
        cout << "NO";
    } else {
        cout << "YES" << "\n";
        string res = "";
        int r = exit_r;
        int c = exit_c;
        while (r != start_r || c != start_c) {
            if (breadcrumbs[r][c] == 'U') {
                res += 'D';
                r--;
            } else if (breadcrumbs[r][c] == 'D') {
                res += 'U';
                r++;
            } else if (breadcrumbs[r][c] == 'R') {
                res += 'L';
                c++;
            } else {
                res += 'R';
                c--;
            }
        }
        cout << res.size() << "\n";
        reverse(res.begin(), res.end());
        cout << res;
    }

    return 0;
}