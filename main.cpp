#include <bits/stdc++.h>

using namespace std;

int di[] = {-1,  0, +1,  0};
int dj[] = { 0, -1,  0, +1};

int dijkstra(vector<vector<int>>& a) {
    set<pair<int, pair<int, int>>> s;
    vector<vector<int>> d(a.size(), vector<int>(a[0].size(), int(1e9)));
    d[0][0] = 0;
    s.insert({0, {0, 0}});
    while (!s.empty()) {
        auto v = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i < 4; i++) {
            int gi = v.first + di[i];
            int gj = v.second + dj[i];
            if (gi >= 0 && gj >= 0 && gi < a.size() && gj < a[0].size() && d[gi][gj] > d[v.first][v.second] + a[gi][gj]) {
                s.erase({d[gi][gj], {gi, gj}});
                d[gi][gj] = d[v.first][v.second] + a[gi][gj];
                s.insert({d[gi][gj], {gi, gj}});
            }
        }
    }
    return d.back().back();
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << dijkstra(a) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}