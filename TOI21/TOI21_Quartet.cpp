#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;
int n, m, u, v;
int sz[200200], deg[200200], ans = 0;
vector<int> vc[200200];

void dfs1(int u, int pa) {
    sz[u] = (u <= n);
    for (int v : vc[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int pa) {
    if(u > n){ 
        vector<int> pref(5, 0), a;
        for (int v : vc[u]) {
            if(sz[v] > sz[u]) a.push_back(n - sz[u]);
            else a.push_back(sz[v]);
        }
        pref[0] = 1;
        for(int x : a){
            for(int i = 4; i >= 1; --i){
                pref[i] = (pref[i] + (pref[i - 1] * x) % mod) % mod;
            }
        }
        ans = (ans + pref[4]) % mod;
    }
    for (int v : vc[u]) {
        if(v == pa) continue;
        dfs2(v, u);
    }
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n + m - 1; ++i) {
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    cout << ans << '\n';
}
