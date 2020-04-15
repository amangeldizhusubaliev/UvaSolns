#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    unordered_map<int64_t, int> m;
    vector<int> a(5);
    while (scanf("%d", &n) && n) {
        int q = 0, ans = 0;
        m.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &a[j]);
            }
            sort(a.begin(), a.end());
            int64_t h = 0;
            for (int i : a) {
                h = h * 1000 + i;
            }
            m[h]++;
            if (m[h] > q) {
                ans = m[h]; 
                q = m[h];
            } else if (m[h] == q) {
                ans += m[h];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}