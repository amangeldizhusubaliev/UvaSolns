#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests; scanf("%d", &tests);
    vector<int> a;
    unordered_map<int, int> m;
    while (tests--) {
        int n; scanf("%d", &n);
        a.resize(n);
        m.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && m[a[r]] == 0) {
                m[a[r++]]++;
            }
            ans = max(ans, int(m.size()));
            m[a[l]]--;
            if (m[a[l]] == 0) {
                m.erase(a[l]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}