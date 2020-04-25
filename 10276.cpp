#include <bits/stdc++.h>

using namespace std;

int a[50], n;

int f(int v = 1) {
    int r = v - 1;
    for (int i = 0; i < n; i++) {
        int s = sqrt(a[i] + v);
        if (a[i] == 0 || s * s == a[i] + v) {
            a[i] = v;
            r = max(r, f(v + 1));
            break;
        }
    }
    return r;
}

int main() {
    int tests; scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        printf("%d\n", f());
    }
    return 0;
}