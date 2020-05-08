#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> u; 

void dfs(int v, int& ans) {
    u[v] = 1;
    ans++;
    for (int to : g[v]) {
        if (!u[to]) {
            dfs(to, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while (tests--) {
        int n, m, l; cin >> n >> m >> l;
        g.assign(n, vector<int>(0));
        u.assign(n, 0);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y; 
            g[--x].emplace_back(--y);
        }
        int ans = 0;
        while (l--) {
            int x; cin >> x;
            if (u[--x] == 0) {
                dfs(x, ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}