#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> m;
    int x; 
    vector<int> v;
    while (scanf("%d", &x) == 1) {
        if (m[x]++ == 0) {
            v.emplace_back(x);
        }
    }
    for (int i : v) {
        printf("%d %d\n", i, m[i]);
    }
    return 0;
}