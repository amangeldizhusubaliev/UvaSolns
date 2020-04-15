#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
    int n, q; scanf("%d%d", &n, &q);
    unordered_map<string, double> m;
    for (int i = 0; i < n; i++) {
        double x; scanf("%s%lf", &s, &x);
        m[string(s)] = x;
    }
    while (q--) {
        double sm = 0;
        while (scanf("%s", &s) && s[0] != '.') {
            if (m.count(string(s))) {
                sm += m[string(s)];
            }
        }
        printf("%.0f\n", sm);
    }
    return 0;
}