#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests; scanf("%d", &tests);
    unordered_map<int, int64_t> m;
    vector<vector<int>> a;
    vector<int> ans;
    for (int test = 1; test <= tests; test++) {
        int n; scanf("%d", &n);
        m.clear();
        a.assign(n, vector<int>(0));
        ans.assign(n, 0);
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            while (x--) {
                int y; scanf("%d", &y);
                a[i].emplace_back(y);
                m[y] |= 1LL << i;
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j : a[i]) {
                if (__builtin_popcountll(m[j]) == 1) {
                    ans[i]++;
                    m[j] = 3;
                }
            }
            total += ans[i];
        }
        printf("Case %d:", test);
        for (int i = 0; i < n; i++) {
            printf(" %.6f%c", ans[i] * 100.0 / total, '%');
        }
        puts("");
    }
    return 0;
}