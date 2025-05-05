#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, q, dp[(1<<20)], val[(1<<20)], w;
string s;

int binary(string s){
    int cnt = 0;
    for(int i = 1; i<=n; ++i) cnt+=((s[i - 1] - '0')*(1<<(n - i)));
    return cnt;
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i<=(1<<n); ++i){
        cin >> s >> w;
        int a = binary(s);
        val[a] = w;
    }
    for(int i = 1; i<(1<<n); ++i) dp[i] = LLONG_MIN;
    for(int i = 0; i<(1<<n); ++i){
        for(int j = 0; j<n; ++j){
            if(i&(1<<j)) dp[i] = max(dp[i], dp[i^(1<<j)] + val[i]);
            if(j > 0 && (i&(1<<j)) && (i&(1<<(j - 1)))) dp[i] = max(dp[i], dp[i^(1<<j)^(1<<(j - 1))] + val[i]);
            if(j < n - 1 && (i&(1<<j)) && (i&(1<<(j+1)))) dp[i] = max(dp[i], dp[i^(1<<j)^(1<<(j+1))] + val[i]);
        }
    }
    while(q--){
        cin >> s;
        cout << dp[binary(s)] << '\n';
    }
}
