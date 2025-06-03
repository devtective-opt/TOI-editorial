/*
    Author : detective conan
    Problem : TOI21_Crystal
    Created : 25/05/2025 10:56 UTC+7
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

const int MAX_U = 1010, MAX_K = 1010, MAX_N = 1e5 + 10;
int u, k, n, ans;
vec<tiii> cry;
vec<int> v;
map<int, int> comp;

struct FenwickTree{
    int fw[MAX_N];
    void upd(int i, int val){
        for(; i < MAX_N; i += (i&-i)) fw[i] = max(fw[i], val);
    }
    int qry(int i, int mx = 0){
        for(; i > 0; i -= (i&-i)) mx = max(mx, fw[i]);
        return mx;
    }
}ftree[MAX_U];

void solve(){
    cin >> u >> k >> n;
    cry.resize(n + 1);
    FOR(i, 1, n) cin >> get<1>(cry[i]) >> get<2>(cry[i]) >> get<0>(cry[i]), v.pb(get<1>(cry[i]));
    sort(cry.begin() + 1, cry.begin() + 1 + n);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    FOR(i, 0, v.size() - 1) comp[v[i]] = i + 1;
    FOR(i, 1, n){
        int t = get<0>(cry[i]), p = get<1>(cry[i]), w = get<2>(cry[i]);
        int it = comp[p];
        int cal = ftree[w].qry(it - 1) + 1;
        cal = max(cal, ftree[MAX_U - 1].qry(it - 1) - k + 1);
        ans = max(ans, cal);
        ftree[MAX_U - 1].upd(it, cal);
        ftree[w].upd(it, cal);
    }
    cout << ans << '\n';
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}