#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> g;

int bfs(int v, int x) {
    unordered_map<int, int> u;
    queue<pair<int, int>> q;
    q.push(make_pair(v, x));
    u[v] = 1;
    int ans = 0;
    while (!q.empty()) {
        ans++;
        int cv = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cx != 0) {
            for (int to : g[cv]) {
                if (u[to] == 0) {
                    u[to] = 1;
                    q.push(make_pair(to, cx - 1));
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, cs = 0; 
    while (cin >> m) {
        g.clear();
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        int v, x;
        while (cin >> v >> x) {
            if (v + x == 0) {
                break;
            }
            cout << "Case " << ++cs << ": " << g.size() - bfs(v, x) << " nodes not reachable from node " << v << " with TTL = " << x << ".\n";
        }
    }

    return 0;
}