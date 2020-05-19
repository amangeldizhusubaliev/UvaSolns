#include <bits/stdc++.h>

using namespace std;

struct edge {
    int x, y, w;
    edge(int _x = 0, int _y = 0, int _w = 0) : x(_x), y(_y), w(_w) {}
};

int get(int x, vector<int>& p) {
    return x == p[x] ? x : p[x] = get(p[x], p);
}

void solve(int n, int m) {
    vector<edge> e;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        e.emplace_back(edge(x, y, w));
        sum += w;
    }
    sort(e.begin(), e.end(), [](edge a, edge b) {
        return a.w < b.w;
    });
    for (auto i : e) {
        int u = get(i.x, p), v = get(i.y, p);
        if (u != v) {
            sum -= i.w;
            p[v] = u;
        }
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    while (cin >> n >> m) {
        if (n + m == 0) {
            break;
        }
        solve(n, m);
    }
    return 0;
}