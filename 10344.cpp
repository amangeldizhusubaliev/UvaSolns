#include <bits/stdc++.h>

using namespace std;

int a[5], b[5];

bool g(int v = 1, int s = b[0]) {
    if (v == 5) {
        if (s == 23) {
            return true;
        }
    } else {
        if (g(v + 1, s + b[v]) || g(v + 1, s - b[v]) || g(v + 1, s * b[v])) {
            return true;
        }
    }
    return false;
}

bool f(int v = 0) {
    if (v == 5) {
        if (g()) {
            return true;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            if (a[i]) {
                b[v] = a[i];
                a[i] = 0;
                if (f(v + 1)) {
                    return true;
                }
                a[i] = b[v];
            }
        }
    }
    return false;
}

int main() {
    while (true) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &a[i]);
        }
        if (a[0] == 0) {
            break;
        }
        puts(f() ? "Possible" : "Impossible");
    }
    return 0;
}