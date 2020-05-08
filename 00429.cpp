#include <bits/stdc++.h>

using namespace std;

inline int dist(string& a, string& b) {
    int r = 0;
    for (int i = 0; i < a.size(); i++) {
        r += a[i] != b[i];
    }
    return r;
}

inline int bfs(int x, int y, vector<vector<int>>& g) {
    vector<int> d(g.size(), 666);
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bool b = false;
        for (int to : g[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                if (to == y) {
                    b = true;
                    break;
                }
                q.push(to);
            }
        }
        if (b) {
            break;
        }
    }
    return d[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string line; getline(cin, line);
    istringstream sinp(line);
    int tests; sinp >> tests;
    getline(cin, line);
    bool q = false;
    while (tests--) {
        if (q) {
            cout << "\n";
        }
        q = true;
        vector<string> w;
        while (getline(cin, line) && line[0] != '*') {
            w.emplace_back(line);
        }
        sort(w.begin(), w.end());
        w.resize(unique(w.begin(), w.end()) - w.begin());
        vector<vector<int>> g(w.size(), vector<int>(0));
        for (int i = 0; i < w.size(); i++) {
            for (int j = i + 1; j < w.size(); j++) {
                if (w[i].size() == w[j].size() && dist(w[i], w[j]) == 1) {
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                }
            }
        }
        while (getline(cin, line) && line.size() > 0) {
            sinp = istringstream(line);
            string a, b; sinp >> a >> b;
            int x = lower_bound(w.begin(), w.end(), a) - w.begin();
            int y = lower_bound(w.begin(), w.end(), b) - w.begin();
            cout << a << " " << b << " " << bfs(x, y, g) << "\n";
        }
    }
    return 0;
}