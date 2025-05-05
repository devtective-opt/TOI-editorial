/*
    Author : detective conan
    Problem : TOI20_sculpture
    Created : 27/03/2025 12:50 UTC+7
*/
#include <bits/stdc++.h>
#define int long long
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define HAVE_TESTCASE false
#define mod (int)(1e9 + 7)
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define ANS(n, s) cout << n << s
#define vec vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ar(t, n) array<t, n>
#define great(a) a, vec<a>, greater<a>
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define lbv(a, m) lower_bound(a.begin(), a.end(), m) - a.begin()
#define ubv(a, m) upper_bound(a.begin(), a.end(), m) - a.begin()
#define lba(a, i, m) lower_bound(a, a + i, m) - a
#define uba(a, i, m) upper_bound(a, a + i, m) - a

using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const int MAX_N = 20020;
int n, w[MAX_N], l[MAX_N], dp1[MAX_N], dp2[MAX_N];
vec<int> vc1, vc2, mach;

void solve(){
    cin >> n;
    FOR(i, 1, n) cin >> w[i] >> l[i];
    vc1.pb(0);
    FOR(i, 1, n){
        if(l[i] >= vc1.back()) vc1.pb(vc1.back() + w[i]);
        int mx = -1;
        rep(j, vc1.size() - 1, 1){
            if(vc1[j - 1] <= l[i]){
                mx = max(mx, j);
                vc1[j] = min(vc1[j - 1] + w[i], vc1[j]);
            }
        }
        dp1[i] = mx;
    } 
    rep(i, n, 1){
        if(vc2.empty()) vc2.pb(l[i]);
        else{
            if(vc2.back() >= w[i]) vc2.pb(min(l[i], vc2.back() - w[i]));
            rep(j, vc2.size() - 1, 1){
                if(vc2[j - 1] >= w[i]) vc2[j] = max(min(l[i], vc2[j - 1] - w[i]), vc2[j]);
            }
            vc2[0] = max(l[i], vc2[0]);
        }
        dp2[i] = vc2.size();
    }
    int ans = -1;
    FOR(i, 2, n){
        int cur = dp1[i - 1] + dp2[i];
        if(cur > ans){
            ans = cur;
            mach.clear();
            mach.pb(i);
        }
        else if(cur == ans) mach.pb(i);
    } 
    cout << ans << '\n';
    for(auto x:mach) cout << x - 1 << ' ';
}

int32_t main(){
    int t = 1;
    if(HAVE_TESTCASE) scanf("%d", &t);
    while(t--) solve();
}
