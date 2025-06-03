/*
    Author : detective conan
    Problem : TOI21_Tech-Sprites
    Created : 24/05/2025 11:54 UTC+7
*/
#include <bits/stdc++.h>
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define FPOR(i, s, t, c) for(int i = s; i <= t; i += c)
#define rmep(i, s, t, c) for(int i = s; i >= t; i -= c)
#define FMOR(i, s, t, c) for(int i = s; i <= t; i *= c)
#define rdep(i, s, t, c) for(int i = s; i >= t; i /= c)
#define HAVE_TESTCASE false
#define ANS(n, s) cout << n << s
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define P pair
#define T tuple
#define vec vector
#define all(a) a.begin(), a.end()
#define great(a) a, vec<a>, greater<a>
#define F first
#define S second
#define pout(n) cout << n.F << ' ' << n.S << '\n';
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lbv(a, m) lower_bound(all(a), m) - a.begin()
#define upv(a, m) upper_bound(all(a), m) - a.begin()
#define lb lower_bound
#define ub upper_bound
 
using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

int n, m, pa[1000010], c[1000010], rm[1000010], ans, id[1000010];
tiii h[1000010];
set<int> s;

int fp(int x){ 
    return pa[x] == x ? x : pa[x] = fp(pa[x]); 
}

void solve(){
    cin >> n >> m;
    FOR(i, 1, n) cin >> get<0>(h[i]) >> get<1>(h[i]), get<2>(h[i]) = i, pa[i] = i;
    sort(h + 1, h + 1 + n);
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        pa[fp(v)] = fp(u);
    }
    FOR(i, 1, n) id[i] = get<2>(h[i]), rm[fp(id[i])] = i;
    FOR(i, 1, n - 1){
        if(fp(id[i]) != fp(id[i + 1]) && rm[fp(id[i])] != i) ans++, rm[fp(id[i])] = max(rm[fp(id[i])], rm[fp(id[i + 1])]), pa[fp(id[i + 1])] = fp(id[i]);
    }
    cout << ans;
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
