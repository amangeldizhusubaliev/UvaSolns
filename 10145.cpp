#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests; scanf("%d\n", &tests);
    bool bline = false;
    unordered_map<int, unordered_set<int>> x, s;
    unordered_set<int> ign;
    while (tests--) {
        if (bline) {
            puts("");
        } else {
            bline = true;
        }
        x.clear(); s.clear(); ign.clear();
        while (true) {
            char mode; scanf("\n%c", &mode);
            if (mode == '#') {
                break;
            }
            int trid, item; scanf("%d%d", &trid, &item);
            if (ign.count(trid)) {
                puts("IGNORED");
                continue;
            }
            if (mode == 'X') {
                if ((x[item].empty() || x[item].count(trid)) && (s[item].empty() || (s[item].size() == 1 && s[item].count(trid)))) {
                    puts("GRANTED");
                    x[item].insert(trid);
                } else {
                    puts("DENIED");
                    ign.insert(trid);
                }
            } else {
                if (x[item].empty() || x[item].count(trid)) {
                    puts("GRANTED");
                    s[item].insert(trid);
                } else {
                    puts("DENIED");
                    ign.insert(trid);
                }
            }
        }
    }
    return 0;
}