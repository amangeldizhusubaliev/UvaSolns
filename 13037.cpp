#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s[3];
    int tests; scanf("%d", &tests);
    for (int cs = 1; cs <= tests; cs++) {
        for (int i = 0; i < 3; i++) {
            s[i].clear();
        }
        int x[6] = {0}; scanf("%d%d%d", &x[0], &x[1], &x[2]);
        for (int i = 0; i < 3; i++) {
            while (x[i]--) {
                int f; scanf("%d", &f);
                s[i].insert(f);
            }    
        }
        for (int p = 0; p < 3; p++) {
            int q = (p + 1) % 3;
            int r = (q + 1) % 3;
            for (int i : s[p]) {
                if (!s[q].count(i) && !s[r].count(i)) {
                    x[p]++;
                } else if (!s[q].count(i)) {
                    x[q + 3]++;
                } else if (!s[r].count(i)) {
                    x[r + 3]++;
                }
            }
        }
        printf("Case #%d:\n%d %d\n%d %d\n%d %d\n", cs, x[0] + 1, x[3] / 2, x[1] + 1, x[4] / 2, x[2] + 1, x[5] / 2);
    }
    return 0;
}