#include <bits/stdc++.h>
using namespace std;

/*
Observations:
the input is a graph

Approach: bfs
we can use level order traversal starting from A, holding
(r, c, path) in the queue. We traverse only on '.' tiles

mark tiles as visited, (dir - first direction we came from)

after we found the solution, build the correct path we took to get there
*/

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n, '.'));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                grid[i][j] = '#';
                q.push({i, j});
            }
        }
    } 
    array<tuple<int, int, char>, 4> dirs = {{{-1, 0, 'D'}, {1, 0, 'U'}, {0, -1, 'R'}, {0, 1, 'L'}}};

    int level = 0;
    while (!q.empty()) {
        const int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            int r = get<0>(q.front());
            int c = get<1>(q.front());

            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r + get<0>(dirs[i]);
                int dc = c + get<1>(dirs[i]);
                char dir = get<2>(dirs[i]);

                if (dr >= 0 && dr < m && dc >= 0 && dc < n && (grid[dr][dc] == '.' || grid[dr][dc] == 'B')) {
                    if (grid[dr][dc] == 'B') {
                        grid[dr][dc] = dir;
                        cout << "YES" << "\n";
                        cout << level + 1 << "\n";

                        r = dr;
                        c = dc;

                        string res = "";
                        while (grid[r][c] != '#') {
                            if (grid[r][c] == 'D')  {
                                res += 'U';
                                r++;
                            }
                            else if (grid[r][c] == 'U') {
                                res += 'D';
                                r--;
                            }
                            else if (grid[r][c] == 'R') {
                                res += 'L';
                                c++;
                            }
                            else {
                                res += 'R';
                                c--;
                            }
                        }
                        
                        reverse(res.begin(), res.end());
                        cout << res;
                        
                        return 0;
                    }
                    q.push({dr, dc});
                    grid[dr][dc] = dir;
                }
            }
        }
        level++;
    }

    cout << "NO";
    return 0;
}