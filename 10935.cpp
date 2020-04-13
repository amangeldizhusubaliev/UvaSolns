#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int n; cin >> n;) {
        if (n == 0) {
            break;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        vector<int> ans;
        while (q.size() > 1) {
            ans.emplace_back(q.front());
            q.pop();
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << "Discarded cards:" << (n == 1 ? "" : " ");
        for (int i = 0; i < ans.size(); i++) {
            if (i) {
                cout << ", ";
            }
            cout << ans[i];
        }
        cout << "\nRemaining card: " << q.front() << "\n";
    }
    return 0;
}