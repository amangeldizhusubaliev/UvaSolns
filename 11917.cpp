#include <bits/stdc++.h>

using namespace std;

char s[20];

int main() {
    int tests; scanf("%d", &tests);
    map<string, int> m;
    for (int test = 1; test <= tests; test++) {
        m.clear();
        int n; scanf("%d", &n);
        while (n--) {
            int x; scanf("%s%d", &s, &x);
            m[string(s)] = x;
        }
        int d; scanf("%d", &d);
        scanf("%s", &s);
        int tmp = m[string(s)];
        printf("Case %d: %s\n", test, (tmp > 0 && tmp <= d) ? "Yesss" : (tmp > 0 && tmp <= d + 5) ? "Late" : "Do your own homework!");
    }
    return 0;
}