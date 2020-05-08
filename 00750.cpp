#include <bits/stdc++.h>

using namespace std;

int d[30], r[8], y, sl, c[8];

void f(int v = 0) {
    if (v == 8) {
        printf("%2d      ", ++sl);
        for (int i = 0; i < 8; i++) {
            printf("%d%c", c[i] + 1, " \n"[i == 7]);
        }
    } else {
        if (v == y) {
            f(v + 1);
        } else {
            for (int i = 0; i < 8; i++) {
                if (r[i] + d[i + v] + d[i - v + 22] == 0) {
                    r[i] = d[i + v] = d[i - v + 22] = 1;
                    c[v] = i;
                    f(v + 1); 
                    r[i] = d[i + v] = d[i - v + 22] = 0;
                }
            }
        }
    }
}

int main() {
    int tests; scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        if (test > 1) {
            puts("");
        }
        puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        int x; scanf("%d%d", &x, &y); 
        x--; y--;
        c[y] = x;
        r[x] = d[x + y] = d[x - y + 22] = 1;
        sl = 0;
        f();
        r[x] = d[x + y] = d[x - y + 22] = 0;
    }
    return 0;
}