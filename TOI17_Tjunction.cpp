#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vec[80001];
bool visited[80001];
vector<int> dis;

void dfs(int u) {
    visited[u] = true;
    for(auto [w,v]:vec[u]) {
        if (!visited[v]) {
            dfs(v);
            dis.push_back(w);
        }
    }
}

bool solve(int mid) {
    int sum=0,cou=0;
    for(auto i:dis) {
        sum += i;
        if (sum>=mid) {
            cou++;
            sum = 0;
        }
    }
    return cou >= 3;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int u,v,w; cin >> u >> v >> w;
        vec[u].push_back({w, v});
        vec[v].push_back({w, u});
    }
    for(int i=0;i<=n;i++) {
        if (vec[i].size()==1) {
            dfs(i);
            break;
        }
    }
    int l=0,r=2e9,ans=0;
    while (l<=r) {
        int mid = (l + r) / 2;
        if (solve(mid)) l = mid + 1, ans = max(ans, mid);
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
