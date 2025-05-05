include<bits/stdc++.h>

using namespace std;

const int mxN = 405;
int rnd,k;
int a[mxN];
pair<int,int> dp[mxN][mxN];
int ans = 0;

void solve(){
    int n; cin>> n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) dp[i][i] = {1,1};
    for(int sz=2;sz<=n;sz++){
        for(int i=1;i+sz-1<=n;i++){
            int l=i , r = i+sz-1;
            dp[l][r] = {dp[l][r-1].first+1,1};
            for(int j=l;j<r;j++){
                if((a[j] == a[r]) &&  (dp[l][j].second < k)){
                    pair<int,int> tmp = {dp[l][j].first + dp[j+1][r-1].first , dp[l][j].second+1};
                    dp[l][r] = min(dp[l][r] , tmp);
                }
            }
        }
    }
    ans = max(ans , dp[1][n].first);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> rnd >> k;
    while(rnd--) solve();
    cout << ans;
    return 0;
}
