#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> p, u, f;

void dfs(int v) {
    u[v] = 1;
    p.emplace_back(v);
    for (int to : g[v]) {
        if (--f[to] == 0) {
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> m) {
        if (n + m == 0) {
            break;
        }
        g.assign(n, vector<int>(0));
        u.assign(n, 0);
        f.assign(n, 0);
        p.clear();
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            g[--x].emplace_back(--y);
            f[y]++;
        }
        for (int i = 0; i < n; i++) {
            if (u[i] == 0 && f[i] == 0) {
                dfs(i);
            }
        }
        bool q = false;
        for (int i : p) {
            if (q) {
                cout << " ";
            }
            q = true;
            cout << i + 1;
        }
        cout << "\n";
    }
    return 0;
}