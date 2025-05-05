/*
Author : detective conan
Problem : TOI18_sausage
*/
#include <bits/stdc++.h>
#define int long long
#define db(n) cout << n << '\n';

using namespace std;

const int mod = 1e9 + 7;
const bool HAVE_TESTCASE = false;

int n, arr[5005], dp[5005][5005], ans[5005];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i], dp[i][i] = arr[i];
    for(int i = 2; i <= n; ++i){
        for(int j = 1; i + j - 1 <= n; ++j){
            int l = j, r = i + j - 1;
            dp[l][r] = max(dp[l + 1][r] + arr[l], dp[l][r - 1] + arr[r]) + abs(arr[l] - arr[r]);
        }
    }
    for(int i = 1; i <= n; ++i){
        ans[i] = dp[1][i];
        for(int j = 1; j < i; ++j){
            ans[i] = max(ans[i], dp[j + 1][i] + ans[j]);
        }
    }
    cout << ans[n] << '\n';
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
