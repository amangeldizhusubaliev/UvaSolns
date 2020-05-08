#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<int>& u) {
    u[v] = 1;
    for (int to : g[v]) {
        if (!u[to]) {
            dfs(to, g, u);
        }
    }
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
        getline(cin, line);
        int n = line[0] - 'A' + 1;
        vector<vector<int>> g(n, vector<int>(0));
        vector<int> u(n, 0);
        while (getline(cin, line) && line.size() > 0) {
            g[line[0] - 'A'].emplace_back(line[1] - 'A');
            g[line[1] - 'A'].emplace_back(line[0] - 'A');
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!u[i]) {
                dfs(i, g, u);
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}