#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;

void gen(int x, string& s, int v = 0) {
    if (v == x) {
        m[s] = m.size() + 1;
    } else {
        char b = v == 0 ? 'a' : s[v - 1] + 1;
        char e = 'z' - x + v + 1;
        for (char i = b; i <= e; i++) {
            s[v] = i;
            gen(x, s, v + 1);
        }
    }
}

char a[10];

int main() {
    for (int i = 1; i <= 5; i++) {
        string temp; temp.resize(i);
        gen(i, temp);
    }
    while (gets(a)) {
        string temp = a;
        printf("%d\n", m.count(temp) ? m[a] : 0);
    }
    return 0;
}