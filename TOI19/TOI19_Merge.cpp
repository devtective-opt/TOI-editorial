/*
    Author : detective conan
    Problem : TOI19_merge
    created : 17/03/2025 10:25 UTC+7
*/
#include <bits/stdc++.h>
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define DB(n, s) cout << n << s
#define ANS(n, s) DB(n,s)
#define HAVE_TESTCASE false
#define mod (int)(1e9 + 7)
#define sum(a, b) (a + b)%mod
#define mul(a, b) ((a%mod) * (b%mod))%mod
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define pb push_back
#define eb emplace_back

using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned i64;

const int MAX_N = 1e5 + 10, MAX_M = 1e5 + 10;
int n, m, q, x[MAX_N], y[MAX_M], s[MAX_N], t[MAX_M];

void solve(){
    cin >> n >> m >> q;
    FOR(i, 0, n - 1) cin >> x[i];
    FOR(i, 1, n) cin >> s[i], s[i] += s[i - 1];
    FOR(i, 0, m - 1) cin >> y[i];
    FOR(i, 1, m) cin >> t[i], t[i] += t[i - 1];
    while(q--){
        int a, b, k; cin >> a >> b >> k;
        int l = -1e9, r = 1e9, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int k1 = s[upper_bound(x, x + n, mid) - x], k2 = t[upper_bound(y, y + m, (mid - b)/a) - y];
            if(k1 + k2 >= k) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        ANS(ans, '\n');
    }
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
