#include <bits/stdc++.h>

using namespace std;

char line[151];
set<string> s;
vector<string> a;
unordered_map<string, int> m;

int main() {
    gets(line);
    int tests; sscanf(line, "%d", &tests);
    for (int test = 1; test <= tests; test++) {
        s.clear(); a.clear(); m.clear();
        while (true) {
            gets(line);
            if (strlen(line) >= 3 && line[0] == 'E' && line[1] == 'N' && line[2] == 'D') {
                break;
            }
            string cur;
            int ln = strlen(line);
            for (int i = 0; i <= ln; i++) {
                if (isalpha(line[i])) {
                    cur += line[i];
                } else if (cur.size() > 0) {
                    s.insert(cur);
                    a.emplace_back(cur);
                    cur = "";
                }
            }
        }
        int ansl = 0, ansr = a.size();
        for (int l = 0, r = 0; l < a.size(); l++) {
            while (r < a.size() && m.size() < s.size()) {
                m[a[r++]]++;
            }
            if (m.size() == s.size() && ansr - ansl > r - l) {
                ansl = l; ansr = r;
            }
            m[a[l]]--;
            if (m[a[l]] == 0) {
                m.erase(a[l]);
            }
        }
        printf("Document %d: %d %d\n", test, ansl + 1, ansr);
    }
    return 0;
}