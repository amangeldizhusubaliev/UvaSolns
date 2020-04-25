#include <bits/stdc++.h>

using namespace std;

int a[8], r[8], d[30];

int f(int v = 0, int s = 0) {
    if (v == 8) {
        return s;
    } else {
        int rt = 8;
        for (int i = 0; i < 8; i++) {
            if (r[i] + d[i + v] + d[i - v + 22] == 0) {
                r[i] = d[i + v] = d[i - v + 22] = 1;
                rt = min(rt, f(v + 1, s + (a[v] != i)));
                r[i] = d[i + v] = d[i - v + 22] = 0;
            }
        }
        return rt;
    }
}

int main() {
    int cs = 0;
    while (scanf("%d", &a[0]) == 1) {
        --a[0];
        for (int i = 1; i < 8; i++) {
            scanf("%d", &a[i]);
            --a[i];
        }
        printf("Case %d: %d\n", ++cs, f());
    }
    return 0;
}