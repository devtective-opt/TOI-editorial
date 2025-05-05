/*
    Author : detective conan
    Problem : TOI11_observatory
    created : 14/03/2025 10:58 UTC+7
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

const int MAX_N = 2020, MAX_M = 2020;
int n, m, k;
i64 qs[MAX_N][MAX_M], tri[MAX_N][MAX_M], ans = -1e9, a[MAX_N][MAX_M];

void solve(){
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j], qs[i][j] = qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] + a[i][j], tri[i][j] = tri[i - 1][j - 1] + qs[i][j] - qs[i - 1][j];
    FOR(i, k, n) FOR(j, k, m) ans = max(ans, tri[i][j] - tri[i - k][j - k] - qs[i][j - k] + qs[i - k][j - k]);
    FOR(i, 1, n + 10) FOR(j, 1, m + 10) qs[i][j] = tri[i][j] = 0;
    FOR(i, 1, n) rep(j, m, 1) qs[i][j] = qs[i - 1][j] + qs[i][j + 1] - qs[i - 1][j + 1] + a[i][j], tri[i][j] = tri[i - 1][j + 1] + qs[i][j] - qs[i - 1][j];
    FOR(i, k, n) rep(j, m - k + 1, 1) ans = max(ans, tri[i][j] - tri[i - k][j + k] - qs[i][j + k] + qs[i - k][j + k]);
    ANS(ans, '\n');
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
