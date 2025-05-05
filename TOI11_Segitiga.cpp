/*
    Author : detective conan
    Problem : TOI11_Segitiga
    created : 14/03/2025 11:11 UTC+7
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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int dp[300][300][3] = {{{0}}};
    FOR(i, 1, n) dp[i][i][s[i] - '0'] = 1;
    FOR(sz, 2, n){
        FOR(i, 1, n - sz + 1){
            int l = i, r = i + sz - 1;
            FOR(j, l, r - 1){
                if(dp[l][j][0] && dp[j + 1][r][2]) dp[l][r][0] = 1;
                if((dp[l][j][0] && dp[j + 1][r][1]) || (dp[l][j][1] && dp[j + 1][r][1]) || (dp[l][j][1] && dp[j + 1][r][2]) || (dp[l][j][2] && dp[j + 1][r][0]) || (dp[l][j][2] && dp[j + 1][r][2])) dp[l][r][1] = 1;
                if((dp[l][j][0] && dp[j + 1][r][0]) || (dp[l][j][1] && dp[j + 1][r][0]) || (dp[l][j][2] && dp[j + 1][r][1])) dp[l][r][2] = 1;
            }
        }
    }
    if(dp[1][n][0]) return void(cout << "yes\n");
    cout << "no\n";
}

int main(){
    conan;
    int t = 20;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
