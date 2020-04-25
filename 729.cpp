#include <bits/stdc++.h>

using namespace std;

char s[20];

void f(int n, int m, int v = 0) {
    if (v == n) {
        puts(s);
    } else {
        if (n - v - 1 >= m) {
            s[v] = '0';
            f(n, m, v + 1);
        }
        if (m) {
            s[v] = '1';
            f(n, m - 1, v + 1);
        }
    }
}

int main() {
    int tests; scanf("%d", &tests);
    bool q = false;
    while (tests--) {
        if (q) {
            puts("");
        }
        q = true;
        int n, m; scanf("%d%d", &n, &m);
        s[n] = 0; 
        f(n, m);
    }
    return 0;
}