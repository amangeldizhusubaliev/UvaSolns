#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> s;
    string tmp;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (isalpha(c) || c == '-') {
            tmp += tolower(c);
        } else if (c == '\n' && tmp.size() > 0 && tmp.back() == '-') {
            tmp.pop_back();
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