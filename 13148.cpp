#include <bits/stdc++.h>

using namespace std;

inline int bp(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) {
            r *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return r;
}

int main() {
    unordered_set<int> a, b;
    for (long long i = 1; i <= int(1e8); i *= 64) {
        a.insert(i);    
    }
    for (int i = 3; i <= 19; i += 2) {
        b.clear();
        int q = bp(i, 6);
        for (long long j = q; j <= int(1e8); j *= q) {
            for (int k : a) {
                if (j * k > int(1e8)) {
                    break;
                }
                b.insert(j * k);
            }
        }
        for (int j : b) {
            a.insert(j);
        }
    }
    int n;
    while (scanf("%d", &n) && n) {
        puts(a.count(n) ? "Special" : "Ordinary");
    }
    return 0;
}