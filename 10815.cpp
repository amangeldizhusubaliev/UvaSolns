#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> s;
    string tmp;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (isalpha(c)) {
            tmp += tolower(c);
        } else if (tmp.size()) {
            s.insert(tmp);
            tmp = "";
        }
    }
    for (const string& i : s) {
        puts(i.c_str());
    }
    return 0;
}