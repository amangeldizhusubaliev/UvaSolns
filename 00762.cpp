#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9);

inline void bfs(int a, int b, const vector<vector<int>>& g, const vector<string>& rdt) {
    queue<int> q;
    q.push(a);
    vector<int> d(rdt.size(), inf);
    vector<int> p(rdt.size(), -1);
    d[a] = 0;
    while (!q.empty() && d[b] == inf) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                p[to] = v;
                if (to == b) {
                    break;
                }
                q.push(to);
            }
        }
    }
    if (d[b] == inf) {
        cout << "No route\n";
    } else {
        vector<pair<int, int>> ans;
        for (int i = p[b], j = b; i != -1; i = p[i], j = p[j]) {
            ans.emplace_back(make_pair(i, j));
        }
        reverse(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << rdt[i.first] << " " << rdt[i.second] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, f = 0;
    unordered_map<string, int> dt;
    vector<string> rdt;
    vector<vector<int>> g;
    while (cin >> m) {
        if (f) {
            cout << "\n";
        }
        f = 1;
        dt.clear();
        rdt.clear();
        g.assign(m + m, vector<int>(0));
        string a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (!dt.count(a)) {
                dt[a] = rdt.size();
                rdt.emplace_back(a);
            }
            if (!dt.count(b)) {
                dt[b] = rdt.size();
                rdt.emplace_back(b);
            }
            int xa = dt[a], xb = dt[b];
            g[xa].emplace_back(xb);
            g[xb].emplace_back(xa);
        }
        cin >> a >> b;
        if (dt.count(a) && dt.count(b)) {
            bfs(dt[a], dt[b], g, rdt);
        } else {
            cout << "No route\n";
        }
    }
    return 0;
}