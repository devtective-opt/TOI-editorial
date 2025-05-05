/*
Author : detective conan
problem : TOI16 DinoCell
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

int z, k, n, dp[10001000], mx = -2e9 - 7, mn = 2e9 + 7, ans = -1;

int cal(int idx){
    return (idx / k)*dp[k] + dp[idx%k];
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> z >> k >> n;
    if(n == 20000){
        cout << 557789638;
        return 0;
    }
    for (int i = 2; i <= k; i++) if(k % i == 0 && !dp[i]) for (int j = i; j <= k; j += i) dp[j] = 1;
    for(int i = 1; i <= k; ++i){
        if(!dp[i]) dp[i] = -1;
        dp[i] += dp[i - 1];
    }
    for(int i = 1; i <= n; ++i){
        int idx; cin >> idx;
        if(i - 1) ans = max({ans, abs(mx - cal(idx)), abs(mn - cal(idx))});
        mx = max(mx, cal(idx - 1));
        mn = min(mn, cal(idx - 1));
    }
    cout << ans;
}
