#include <bits/stdc++.h>

using namespace std;

char p[] = "IEHOVA#";
string w[] = {"forth", "right", "left"};

int n, m, q[7];
char c[8][8];

inline bool ok(int x, int y, int v) {
    return x >= 0 && x < n && y >= 0 && y < m && c[x][y] == p[v];
}

bool f(int x, int y, int v = 0) {
    if (v == 7) {
        return true;
    } else {
        if (ok(x - 1, y, v)) {
            q[v] = 0;
            if (f(x - 1, y, v + 1)) {
                return true;
            }
        } 
        if (ok(x, y + 1, v)) {
            q[v] = 1;
            if (f(x, y + 1, v + 1)) {
                return true;
            }
        }
        if (ok(x, y - 1, v)) {
            q[v] = 2;
            if (f(x, y - 1, v + 1)) {
                return true;
            }
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while (tests--) {
        cin >> n >> m;
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
                if (c[i][j] == '@') {
                    x = i; y = j;
                }
            }
        }
        f(x, y);
        for (int i = 0; i < 7; i++) {
            cout << w[q[i]] << " \n"[i == 6];
        }
    }
    return 0;
}