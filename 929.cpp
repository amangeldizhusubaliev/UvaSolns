#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second

using namespace std;

const int inf = int(1e9);

int df[] = {-1,  0, +1,  0};
int ds[] = { 0, -1,  0, +1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m, inf));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    d[0][0] = a[0][0];
    set<pair<int, pair<int, int>>> q;
    q.insert(mp(0, mp(0, 0)));
    while (!q.empty()) {
        auto v = q.begin()->s;
        q.erase(q.begin());
        for (int i = 0; i < 4; i++) {
            auto to = mp(v.f + df[i], v.s + ds[i]);
            if (to.f < n && to.f >= 0 && to.s < m && to.s >= 0 && 
                        d[to.f][to.s] > d[v.f][v.s] + a[to.f][to.s]) {
                q.erase(mp(d[to.f][to.s], to));
                d[to.f][to.s] = d[v.f][v.s] + a[to.f][to.s];
                q.insert(mp(d[to.f][to.s], to));
            }
        }
    }
    cout << d[n - 1][m - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}