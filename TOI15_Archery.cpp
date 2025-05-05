/*
    Author : detective conan
    Problem : TOI15_archery
    Created : 29/03/2025 16:30 UTC+7
*/
#include <bits/stdc++.h>
#define int long long
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define HAVE_TESTCASE false
#define mod (int)(1e9 + 7)
#define ANS(n, s) cout << n << s
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define vec vector
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define great(a) a, vec<a>, greater<a>
#define all(a) a.begin(), a.end()
#define lbv(a, m) lower_bound(all(a), m) - a.begin()
#define upv(a, m) upper_bound(all(a), m) - a.begin()

using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;

const int MAX_N = 5e5 + 10;
pii box[MAX_N];
int n, h[MAX_N], ans = LLONG_MAX, pos, mn = LLONG_MAX, sum;

void solve(){
    cin >> n;
    FOR(i, 1, n) cin >> box[i].second, mn = min(mn, box[i].second);
    FOR(i, 1, n) cin >> box[i].first, sum += box[i].first;
    sort(box + 1, box + 1 + n);
    FOR(i, 1, n) h[i] = h[i - 1] + box[i].second;
    FOR(i, 1, n){
        if(box[i].first > mn) return void(cout << pos << ' ' << ans << '\n');
        int cnt = h[i - 1] + sum - n*box[i].first;
        if(cnt < ans) ans = cnt, pos = box[i].first;
    }
    cout << pos << ' ' << ans << '\n';
}

int32_t main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
