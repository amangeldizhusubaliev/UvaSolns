#include <bits/stdc++.h>

using namespace std;

char a[100], b[100], s[100];

int main() {
    unordered_map<string, string> m;
    gets(s);
    int n; sscanf(s, "%d", &n);
    for (int i = 0; i < n; i++) {
        gets(a); gets(b);
        m[string(a)] = string(b);
    }
    gets(s);
    int q; sscanf(s, "%d", &q);
    for (int i = 0; i < q; i++) {
        gets(s);
        puts(m[string(s)].c_str());
    }
    return 0;
}