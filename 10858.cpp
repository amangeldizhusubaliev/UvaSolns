#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int n; cin >> n;) {
        if (n == 0) {
            break;
        }
        stack<pair<int, int>> s;
        vector<int> v;
        vector<vector<int>> ans;
        s.push(make_pair(2, n));
        while (!s.empty()) {
            pair<int, int> cur = s.top();
            s.pop();
            if (cur.second == 1) {
                if (v.size() > 1) {
                    ans.emplace_back(v);
                }
            } else {
                bool nx = false;
                for (int j = cur.first; j <= cur.second; j++) {
                    if (cur.second % j == 0 && (cur.second / j >= j || cur.second == j)) {
                        s.push(make_pair(j + 1, cur.second));
                        v.emplace_back(j);
                        s.push(make_pair(j, cur.second / j));
                        nx = true;
                        break;
                    }
                }
                if (nx) {
                    continue;
                }
            }
            if (v.size() > 0) {
                v.pop_back();
            }
        }
        cout << ans.size() << "\n";
        for (const auto& i : ans) {
            bool q = false;
            for (const int& j : i) {
                if (q) {
                    cout << " ";
                }
                q = true;
                cout << j;
            }
            cout << "\n";
        }
    }
    return 0;
}