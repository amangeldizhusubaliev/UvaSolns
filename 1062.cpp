#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string s;
  for (int cs = 1; cin >> s; cs++) {
    if (s[0] == 'e') {
      break;
    }
    vector<stack<char>> v;
    for (char i : s) {
      bool q = true;
      for (int j = 0; j < v.size(); j++) {
        if (v[j].top() >= i) {
          v[j].push(i);
          q = false;
          break;
        }
      }
      if (q) {
        v.emplace_back(stack<char>({i}));
      }
    }
    cout << "Case " << cs << ": " << v.size() << "\n";
  }
  return 0;
}
