#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, l, shop[11];
vector<pair<int, int>> vc[300300], ans;

void dfs(int u, int s, int k){
    if (u == n) {
        ans.emplace_back(s, k);
        return;
    }
    for (auto x : vc[u]) {
        int v = x.first, w = x.second;
        if (w < 0) dfs(v, s - w, k);
        else dfs(v, s, k + w);
    }
}

int stripe(vector<pair<int, int>>& v, int d) {
    sort(v.begin(), v.end(), [](auto& x, auto& y) {
        return x.second < y.second;
    });
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && (v[j].second - v[i].second) * (v[j].second - v[i].second) < d; j++) {
            int dx = v[i].first - v[j].first;
            int dy = v[i].second - v[j].second;
            d = min(d, dx * dx + dy * dy);
        }
    }
    return d;
}

int closestPair(int l, int r) {
    if (r - l + 1 <= 3) {
        int mn = LLONG_MAX;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                int dx = ans[i].first - ans[j].first;
                int dy = ans[i].second - ans[j].second;
                mn = min(mn, dx * dx + dy * dy);
            }
        }
        return mn;
    }
    int mid = (l + r) / 2;
    int d1 = closestPair(l, mid);
    int d2 = closestPair(mid + 1, r);
    int d = min(d1, d2);
    vector<pair<int, int>> strip;
    for (int i = l; i <= r; i++) {
        if ((ans[i].first - ans[mid].first) * (ans[i].first - ans[mid].first) < d) {
            strip.push_back(ans[i]);
        }
    }
    return stripe(strip, d);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> l;
    for (int i = 1; i <= l; ++i) cin >> shop[i];
    for (int i = 0; i < m; ++i) {
        int u, v, s, w;
        cin >> u >> v >> s >> w;
        if (s == 2) vc[u].emplace_back(v, -w);
        else vc[u].emplace_back(v, w);
    }
    dfs(1, 0, 0);
    sort(ans.begin(), ans.end());
    cout << closestPair(0, ans.size() - 1) << "\n";
}
