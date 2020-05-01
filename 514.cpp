#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    int n;
    bool q = false; 
    while (cin >> n && n != 0) {
        q = true;
        v.resize(n);
        while (cin >> v[0] && v[0] != 0) {
            stack<int> s;
            for (int i = 1; i < n; i++) {
                cin >> v[i];
            }
            int p = 0;
            for (int i = 1; i <= n; i++) {
                s.push(i);
                while (s.size() > 0 && s.top() == v[p]) {
                    s.pop();
                    p++;
                }
            }
            if (p == n) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << "\n";
    }
    return 0;
}