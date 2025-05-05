#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
char t;
string s[11];
ll lcm[11], ans = LLONG_MAX;

void dfs(int lvl, ll cnt) {
    if (lvl == n) {
        ans = min(ans, cnt);
        return;
    }
    for (ll i = cnt; i <= lcm[lvl+1] && i < ans; i += lcm[lvl]) {
        if (s[lvl][i % s[lvl].length()] == t) dfs(lvl+1, i);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> t;
    lcm[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ll a = lcm[i];
        ll b = s[i].length();
        lcm[i+1] = a * b / __gcd(a, b);
    }
    dfs(0, 1);
    cout << ans;
    return 0;
}
