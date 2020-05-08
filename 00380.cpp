#include <bits/stdc++.h>

using namespace std;

struct edge {
    int a, b, to;
    edge(int _a = 0, int _b = 0, int _to = 0) : a(_a), b(_b), to(_to) {}
};

vector<edge> g[int(1e4)];
int u[int(1e4)], ut;

int dfs(int v, int t) {
    u[v] = ut;
    for (auto i : g[v]) {
        if (i.a <= t && t <= i.b) {
            return u[i.to] < ut ? dfs(i.to, t) : 9999;
        }
    }
    return v;
}

int main() {
    puts("CALL FORWARDING OUTPUT");
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("SYSTEM %d\n", i);
        int u;
        for (int i = 1; i <= 9998; i++) {
            g[i].clear();
        }
        while (scanf("%d", &u) && u != 0) {
            int a, b, v; scanf("%d%d%d", &a, &b, &v);
            g[u].emplace_back(edge(a, a + b, v));
        }
        int a;
        while (scanf("%d", &a) && a != 9000) {
            int b; scanf("%d", &b); ++ut;
            printf("AT %04d CALL TO %04d RINGS %04d\n", a, b, dfs(b, a));
        }
    }
    puts("END OF OUTPUT");
    return 0;
}