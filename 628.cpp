#include <bits/stdc++.h>

using namespace std;

vector<string> w;
vector<int> p;
string s;

void f(int v = 0) {
    if (v == s.size()) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cout << p[i];
            } else {
                cout << w[p[i]];
            }
        }
        cout << "\n";
    } else {
        if (s[v] == '0') {
            for (int i = 0; i < 10; i++) {
                p[v] = i;
                f(v + 1);
            }
        } else {
            for (int i = 0; i < w.size(); i++) {
                p[v] = i;
                f(v + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        cout << "--\n";
        w.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> s;
            p.resize(s.size());
            f();
        } 
    }
    return 0;
}