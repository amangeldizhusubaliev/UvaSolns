#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    unordered_set<string> ans;
    vector<string> a;   
    gets(s);
    int tests; sscanf(s, "%d", &tests);
    for (int t = 1; t <= tests; t++) {
        ans.clear();
        a.clear();
        gets(s);
        int n, m; sscanf(s, "%d%d", &n, &m);
        while (n--) {
            gets(s);
            a.emplace_back(string(s));
        }
        while (m--) {
            gets(s);
            for (int i = 0; i < a.size(); i++) {
                ans.insert(a[i] + string(s));
            }
        }
        cout << "Case " << t << ": " << ans.size() << "\n";
    }
    return 0;
}