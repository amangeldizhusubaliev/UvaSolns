#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    multiset<int> s;
    while (scanf("%d", &n) && n) {
        s.clear();
        int64_t ans = 0;
        while (n--) {
            int x; scanf("%d", &x);
            while (x--) {
                int y; scanf("%d", &y);
                s.insert(y);
            }
            ans += *s.rbegin() - *s.begin();
            s.erase(s.begin());
            s.erase(--s.end());
        }
        printf("%lld\n", ans);
    }
    return 0;
}