#include <bits/stdc++.h>

using namespace std;

vector<int> a;
pair<int, int> b;
int n;

void f(int v = 0, int s = 0, int m = 0) {
    if (v == a.size()) {
        if (s > b.second) {
            b = make_pair(m, s);
        }
    } else {
        f(v + 1, s, m);
        if (s + a[v] <= n) {
            f(v + 1, s + a[v], m | (1 << v));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    string line;
    while (getline(cin, line)) {
        istringstream sinp(line);
        sinp >> n;
        a.clear();
        b = make_pair(0, 0);
        int x; sinp >> x;
        while (sinp >> x) {
            a.emplace_back(x);
        }
        f();
        for (int i = 0; i < a.size(); i++) {
            if ((b.first >> i) & 1) {
                cout << a[i] << " ";
            }
        }
        cout << "sum:" << b.second << "\n";
    }
    return 0;
}