#include <bits/stdc++.h>

using namespace std;

char s[20], z[2];

int main() {
    int n, p; scanf("%d%d", &n, &p);
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        double tmp; scanf("%s%lf", &s, &tmp);
        m[string(s)] = tmp * 10;
    }
    for (int i = 1; i <= p; i++) {
        int sm = 0;
        while (true) {
            scanf("%s%s", &s, &z);
            sm += m[string(s)];
            if (z[0] != '+') {
                break;
            }
        }
        int x; scanf("%d", &x); x *= 10;
        //printf("%.1f %s %d   <---------------->   ", sm, z, x);
        bool q = false;
        if (z[1] != '=') {
            if (z[0] == '=' && sm == x) {
                q = true;
            } else if (z[0] == '<' && sm < x) {
                q = true;
            } else if (z[0] == '>' && sm > x) {
                q = true;
            }
        } else {
            if (z[0] == '<' && sm <= x) {
                q = true;
            } else if (z[0] == '>' && sm >= x) {
                q = true;
            }
        }
        printf("Guess #%d was %scorrect.\n", i, q ? "" : "in");
    }
    return 0;
}