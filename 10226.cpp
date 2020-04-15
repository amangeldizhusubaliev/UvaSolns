#include <bits/stdc++.h>

using namespace std;

char s[35];
map<string, int> m;
int q;

int main() {
    gets(s);
    int tests; sscanf(s, "%d", &tests);
    gets(s);
    bool f = false;
    while (tests--) {
        m.clear();
        q = 0;
        while (gets(s)) {
            if (strlen(s) == 0) {
                break;
            }
            m[string(s)]++;
            q++;
        }
        if (f) {
            puts("");
        }
        for (const auto& i : m) {
            printf("%s %.4f\n", i.first.c_str(), i.second * 100.0 / q);
        }
        f = true;
    } 
    return 0;
}