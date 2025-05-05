/*
    Author : detective conan
    Problem : TOI11 Labor
    created : 14/03/2025 10:08 UTC+7
*/
#include <bits/stdc++.h>
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define HAVE_TESTCASE false
#define DB(n, s) cout << n << s
#define ANS(n, s) DB(n, s)
#define mod (int)(1e9 + 7)
#define sum(a, b) ((a%mod) + (b%mod))%mod
#define mul(a, b) ((a%mod) * (b%mod))%mod
#define conan cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;
using i64 = int64_t;
using u64 = unsigned i64;
using u32 = unsigned;

const i64 MAX_N = 1e12 + 10;
const int MAX_M = 1e6 + 10;
int m, lb[MAX_M];
i64 n;

void solve(){
    cin >> m >> n;
    FOR(i, 1, m) cin >> lb[i];
    i64 l = 0ll, r = 1e18, ans = -1ll;
    while(l <= r){
        i64 mid = (l + r) >> 1ll, cnt = 0ll;
        FOR(i, 1, m) cnt += (mid / (i64)(lb[i]));
        if(cnt >= n) ans = mid, r = mid - 1ll;
        else l = mid + 1ll;
    }
    ANS(ans, '\n');
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
