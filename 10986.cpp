#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second

using namespace std;

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        g[x].emplace_back(mp(y, w));
        g[y].emplace_back(mp(x, w));
    }
    vector<int> d(n, INT_MAX);
    d[a] = 0;
    set<pair<int, int>> q;
    q.insert(mp(0, a));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto to : g[v]) {
            if (d[to.f] > d[v] + to.s) {
                q.erase(mp(d[to.f], to.f));
                d[to.f] = d[v] + to.s;
                q.insert(mp(d[to.f], to.f));
            }
        }
    }
    if (d[b] == INT_MAX) {
        cout << "unreachable\n";
    } else {
        cout << d[b] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}