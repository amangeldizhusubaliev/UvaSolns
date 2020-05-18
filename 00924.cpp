#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

inline void bfs(int x, vector<vector<int>>& g) {
    if (g[x].empty()) {
        cout << "0\n";
        return;
    }
    queue<int> q;
    vector<int> d(g.size(), inf), p(g.size(), 0);
    d[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                p[d[to]]++;
                q.push(to);
            }
        }
    }
    auto f = max_element(p.begin(), p.end());
    cout << *f << " " << f - p.begin() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x--) {
            int j; cin >> j;
            g[i].emplace_back(j);
        }
    }
    int tests; cin >> tests;
    while (tests--) {
        int x; cin >> x;
        bfs(x, g);
    }
    return 0;
}