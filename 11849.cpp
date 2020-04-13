#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m) {
        if (n + m == 0) {
            break;
        }
        unordered_set<int> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            ans += s.count(x);
        }
        cout << ans << "\n";
    }

    return 0;
}