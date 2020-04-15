#include <bits/stdc++.h>

using namespace std;

char a[10], b[10], s[21];

int main() {
    map<string, string> m;
    while (gets(s)) {
        if (strlen(s) == 0) {
            break;
        }
        sscanf(s, "%s%s", &a, &b);
        m[string(b)] = string(a);
    }
    while (gets(s)) {
        puts(m.count(string(s)) ? m[string(s)].c_str() : "eh");
    }
    return 0;
}