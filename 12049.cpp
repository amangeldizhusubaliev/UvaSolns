#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests; scanf("%d", &tests);
    unordered_multiset<int> s;
    while (tests--) {
        s.clear();
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            s.insert(x);
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int x; scanf("%d", &x);
            if (s.count(x)) {
                cnt++;
                s.erase(s.find(x));
            }
        }
        printf("%d\n", n + m - cnt * 2);
    }
    return 0;
}