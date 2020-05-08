#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,  0, +1,  0};
int dy[] = { 0, -1,  0, +1};

vector<string> c;

inline bool ok(int x, int y) {
    return c.size() > x && c[0].size() > y && x >= 0 && y >= 0 && c[x][y] == ' ';
}

void dfs(int vx, int vy) {
    c[vx][vy] = '#';
    for (int i = 0; i < 4; i++) {
        int gx = vx + dx[i];
        int gy = vy + dy[i];
        if (ok(gx, gy)) {
            dfs(gx, gy);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string line; getline(cin, line);
    istringstream sinp(line);
    int tests; sinp >> tests;
    while (tests--) {
        c.clear(); 
        int x, y;
        while (getline(cin, line) && line[0] != '_') {
            c.emplace_back(line);
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '*') {
                    x = c.size() - 1;
                    y = i;
                }
            }
        }
        dfs(x, y);
        for (const auto& i : c) {
            cout << i << "\n";
        }
        cout << line << "\n";
    }
    return 0;
}