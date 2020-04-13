#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack<string> s;
    int n; cin >> n;
    while (n--) {
        string type; cin >> type;
        if (type[0] == 'S') {
            string name; cin >> name;
            s.push(name);
        } else if (type[0] == 'K') {
            if (s.size() > 0) {
                s.pop();
            }
        } else if (type[0] == 'T') {
            if (s.size() == 0) {
                cout << "Not in a dream\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }
}