/*
    Author : detective conan
    Problem : toi19_energy
    Created : 29/03/2025 21:48 UTC+7
*/
#include <bits/stdc++.h>
#define int long long
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define mod (int)(1e9 + 7)
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define vec vector
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define great(a) a, vec<a>, greater<a>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lbv(a, m) lower_bound(all(a), m) - a.begin()
#define ubv(a, m) upper_bound(all(a), m) - a.begin()
#define HAVE_TESTCASE false
#define ANS(n, s) cout << n << s

using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;

const int MAX_N = 303, MAX_K = 10;
int A[MAX_N], n, K, d, dp[MAX_K][MAX_N][MAX_N], qs[MAX_N];

void solve(){
    cin >> n >> K >> d;
    FOR(i, 1, n) cin >> A[i], qs[i] = qs[i - 1] + A[i];
    FOR(i, 1, n) FOR(j, 1, n) dp[1][i][j] = 1;
    FOR(k, 2, K){
        FOR(sz, 2, n){
            FOR(i, 1, n - sz + 1){
                int l = i, r = i + sz - 1;
                FOR(j, l, r - 1){
                    int sumL = qs[r] - qs[j];
                    int sumR =  qs[j] - qs[l - 1];
                    if(abs(sumL - sumR) <= d) dp[k][l][r] += (dp[k - 1][l][j]*dp[k - 1][j + 1][r])%mod;
                    dp[k][l][r] %= mod;
                }
            }
        }
    }
    cout << dp[K][1][n] << '\n';
}

int32_t main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
