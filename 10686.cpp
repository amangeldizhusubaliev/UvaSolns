#include <bits/stdc++.h>

using namespace std;

char s[121], z[121];

int main() {
    gets(s);
    int tests; sscanf(s, "%d", &tests);
    string name[25];
    vector<int> w, u;
    unordered_map<string, vector<int>> dict;
    while (tests--) {
        dict.clear();
        gets(s);
        int n; sscanf(s, "%d", &n);
        w.assign(n + 1, 0);
        u.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            gets(s);
            int q; sscanf(s, "%s%d%d", &z, &q, &w[i]);
            //printf("DEBUG :: ||%s %d %d||\n", z, q, w[i]);
            name[i] = z;
            while (q--) {
                gets(z);
                sscanf(z, "%s", &s);
                //printf("DEBUG :: ||%s||\n", s);
                dict[string(s)].emplace_back(i);
            }
        }
        for (auto& i : dict) {
            sort(i.second.begin(), i.second.end());
            i.second.resize(unique(i.second.begin(), i.second.end()) - i.second.begin());
        }
        while (gets(s)) {
            if (strlen(s) == 0) {
                break;
            }
            //printf("DEBUG :: ||%s||\n", s);
            int ln = strlen(s);
            string cur = "";
            for (int i = 0; i <= ln; i++) {
                if (isalpha(s[i])) {
                    cur += s[i];
                } else if (cur.size() > 0) {
                    if (dict.count(cur)) {
                        //printf("DEBUG :: ||%s||\n", cur.c_str());
                        vector<int>& tmp = dict[cur];
                        for (int& ii : tmp) {
                            //printf("DEBUG :: ||%s||\n", name[ii].c_str());
                            u[ii]++;
                            ii = 0;
                        }
                    }
                    cur = "";
                }
            }
        }
        bool q = false;
        for (int i = 1; i <= n; i++) {
            if (w[i] <= u[i]) {
                if (q) {
                    putchar(',');
                }
                q = true;
                printf("%s", name[i].c_str());
            }
        }
        puts(q ? "" : "SQF Problem.");
    }
    return 0;
}