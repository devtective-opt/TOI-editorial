/*
    Author : detective conan
    Problem : TOI11 cannon
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

const int MAX_N = 1e6 + 10, MAX_M = 1010, MAX_K = 410, MAX_L = 5e5 + 10;
int n, m, k, l, can[MAX_N], b;

void solve(){
    cin >> n >> m >> k >> l;
    FOR(i, 1, n) cin >> can[i];
    while(k--){
        int ans = 0, cur = 0;
        FOR(i, 1, m){
            cin >> b;
            int lb = lower_bound(can + 1, can + 1 + n, max(b - l, cur + 1)) - can + 1;
            int rb = upper_bound(can + 1, can + 1 + n, b + l) - can + 1;
            ans += (rb - lb);
            cur = b + l;
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
