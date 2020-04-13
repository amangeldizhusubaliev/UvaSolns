#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while (tests--) {
        int n, m; cin >> m >> n;
        m *= 100;
        queue<int> q[2];
        for (int i = 0; i < n; i++) {
            int x; string s; cin >> x >> s;
            if (s[0] == 'l') {
                q[0].push(x);
            } else {
                q[1].push(x);
            }
        }
        int t = 0, ans = 0;
        while (q[0].size() + q[1].size() > 0) {
            int sm = 0;
            while (q[t].size() > 0 && q[t].front() + sm <= m) {
                sm += q[t].front();
                q[t].pop();
            }
            if (sm != 0 || q[t ^ 1].size() != 0) {
                t ^= 1;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}