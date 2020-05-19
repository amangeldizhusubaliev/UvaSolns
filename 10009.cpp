#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9);

void bfs(int a, int b, vector<vector<int>>& g) {
    queue<int> q;
    vector<int> d(26, inf), p(26, -1);
    q.push(a);
    d[a] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push(to);
            }
        }
    }
    string ans;
    for (int i = b; i != -1; i = p[i]) {
        ans += char(i + 'A');
    }
    for (auto i = ans.rbegin(); i != ans.rend(); i++) {
        cout << *i;
    }
    cout << "\n";
}

void solve() {
    int m, q; cin >> m >> q;
    string a, b;
    vector<vector<int>> g(26, vector<int>(0));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a[0] - 'A'].emplace_back(b[0] - 'A');
        g[b[0] - 'A'].emplace_back(a[0] - 'A');
    }
    while (q--) {
        cin >> a >> b;
        bfs(a[0] - 'A', b[0] - 'A', g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    bool f = false;
    while (tests--) {
        if (f) {
            cout << "\n";
        }
        f = true;
        solve();
    }
    return 0;
}