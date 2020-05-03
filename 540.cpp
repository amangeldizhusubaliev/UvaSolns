#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    unordered_map<int, int> m;
    vector<queue<int>> v;
    for (int test = 1; cin >> n && n != 0; test++) {
        v.assign(n, queue<int>());
        queue<int> q;
        m.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = 0; j < x; j++) {
                int y; cin >> y;
                m[y] = i;
            }
        }
        cout << "Scenario #" << test << "\n";
        string s;
        while (cin >> s) {
            if (s == "STOP") {
                break;
            } else if (s == "ENQUEUE") {
                int x; cin >> x;
                int c_x = m[x];
                if (v[c_x].empty()) {
                    q.push(c_x);
                }
                v[c_x].push(x);
            } else {
                int c_x = q.front();
                int x = v[c_x].front();
                v[c_x].pop();
                cout << x << "\n";
                if (v[c_x].empty()) {
                    q.pop();
                }
            }
        }
        cout << "\n";
    }
    return 0;
}