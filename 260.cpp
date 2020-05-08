#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1,  0,  0, +1, +1};
const int dy[] = {-1,  0, -1, +1,  0, +1};

inline bool ok(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool dfsw(int x, int y, vector<vector<char>>& c, vector<vector<int>>& u, int n) {
    u[x][y] = 1;
    if (y == n - 1) {
        return true;
    }
    for (int i = 0; i < 6; i++) {
        int gx = x + dx[i];
        int gy = y + dy[i];
        if (ok(gx, gy, n) && u[gx][gy] == 0 && c[gx][gy] == 'w' && dfsw(gx, gy, c, u, n)) {
            return true;
        }
    }
    return false;
}

bool dfsb(int x, int y, vector<vector<char>>& c, vector<vector<int>>& u, int n) {
    u[x][y] = 1;
    if (x == n - 1) {
        return true;
    }
    for (int i = 0; i < 6; i++) {
        int gx = x + dx[i];
        int gy = y + dy[i];
        if (ok(gx, gy, n) && u[gx][gy] == 0 &&  c[gx][gy] == 'b' && dfsb(gx, gy, c, u, n)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, cs = 0;
    while (cin >> n && n) {
        vector<vector<char>> c(n, vector<char>(n));
        vector<vector<int>> u(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            if (u[i][0] == 0 && c[i][0] == 'w' && dfsw(i, 0, c, u, n)) {
                cout << ++cs << " W\n";
                break; 
            } 
            if (u[0][i] == 0 && c[0][i] == 'b' && dfsb(0, i, c, u, n)) {
                cout << ++cs << " B\n";
                break;
            }
        }
    }
    return 0;
}