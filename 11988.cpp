#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string line;
    while (getline(cin, line)) {
        list<char> l;
        auto it = l.begin();
        for (char i : line) {
            if (i == '[') {
                it = l.begin();
            } else if (i == ']') {
                it = l.end();
            } else {
                it = l.insert(it, i);
                it++;
            }
        }
        for (char i : l) {
            cout << i;
        }
        cout << "\n";
    }
    return 0;
}