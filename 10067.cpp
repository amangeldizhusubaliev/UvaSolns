#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9);

int readConf() {
    int r = 0;
    for (int i = 0; i < 4; i++) {
        int x; cin >> x;
        r = r * 10 + x;
    }
    return r;
}

int mprv[] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};
int mnxt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int mdiv[] = {1, 10, 100, 1000};
int mmod[] = {10, 100, 1000, 10000};

void solve() {
    int a = readConf(), b = readConf();
    int x; cin >> x;
    vector<int> ban(10000, 0), d(10000, inf);
    while (x--) {
        ban[readConf()] = 1;
    }
    d[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int c = (v % mmod[i]) / mdiv[i];
            int to = v + (mprv[c] - c) * mdiv[i];
            if (!ban[to] && d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
            to += (mnxt[c] - mprv[c]) * mdiv[i];
            if (!ban[to] && d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    cout << (d[b] == inf ? -1 : d[b]) << "\n";
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