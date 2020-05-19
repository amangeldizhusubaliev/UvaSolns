#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<double> x(n), y(n), d(n, 0);
    vector<int> u(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (i) {
            d[i] = hypot(x[0] - x[i], y[0] - y[i]);
        }
    }
    u[0] = 1;
    double ans = 0;
    for (int e = 0; e < n - 1; e++) {
        int mi = -1;
        for (int i = 1; i < n; i++) {
            if (!u[i] && (mi == -1 || d[mi] > d[i])) {
                mi = i;
            }
        }
        ans += d[mi];
        u[mi] = 1;
        for (int i = 0; i < n; i++) {
            if (!u[i]) {
                d[i] = min(d[i], hypot(x[mi] - x[i], y[mi] - y[i]));
            }
        }
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    bool f = false;
    while (tests--) {
        if (f) {
            cout << "\n";
        }
        f = true;
        solve();
    }
    return 0;
}