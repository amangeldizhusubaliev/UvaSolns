#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -1,  0,  0,  0, +1, +1, +1};
const int dy[] = {-1,  0, +1, -1,  0, +1, -1,  0, +1};

inline bool ok(int x, int y, int n, int m) {
    return x < n && x >= 0 && y < m && y >= 0;
}

void dfs(int vx, int vy, vector<vector<char>>& c, vector<vector<char>>& u) {
    u[vx][vy] = 1;
    for (int i = 0; i < 9; i++) {
        int gx = vx + dx[i];
        int gy = vy + dy[i];
        if (ok(gx, gy, c.size(), c[0].size()) && u[gx][gy] == 0 && c[gx][gy] == '@') {
            dfs(gx, gy, c, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; 
    while (cin >> n >> m) {
        if (n + m == 0) {
            break;
        }
        vector<vector<char>> c(n, vector<char>(m));
        vector<vector<char>> u(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!u[i][j] && c[i][j] == '@') {
                    ans++;
                    dfs(i, j, c, u);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}