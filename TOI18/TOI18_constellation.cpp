#include<bits/stdc++.h>

using namespace std;

const int mod = 1e6+3;
int dp[1501][1501], qs1[1501][1501], qs2[1501][1501], n, m, k, ans;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=m; ++j){
            char s; cin >> s;
            qs1[i+600][j+600] = (s == '#');
            qs2[i+600][j+600] = (s == '#');
        }
    }
    for(int i = 1; i<=1500; ++i){
        for(int j = 1; j<=1500; ++j){
            qs1[i][j]+=qs1[i - 1][j + 1];
            qs2[i][j]+=qs2[i - 1][j - 1];
        }
    }
    for(int i = 1; i<=1500; ++i){
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j<i; ++j){
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%mod;
        }
    }
    for(int l = 1; l <= n+m; ++l){
        for(int i = 601; i<=n + 600; ++i){
            for(int j = 601; j<=m + 600; ++j){
                int cnt = 0;
                cnt+=(qs1[i][j - l] - qs1[i - l - 1][j + 1]);
                cnt+=(qs1[i + l][j] - qs1[i - 1][j + l + 1]);
                cnt+=(qs2[i - 1][j + l - 1] - qs2[i - l][j]);
                cnt+=(qs2[i + l - 1][j - 1] - qs2[i][j - l]);
                if(cnt >= k) ans = (ans + dp[cnt][k])%mod;
            }
        }
    }
    cout << ans;
}
