#include<bits/stdc++.h>

using namespace std;

struct data
{
    int sx,sy,nx,ny;
};

int dp[20][20001];
data first,last,warp[20001];
int m,n,k,p,dis = 1e9+7,pass;

int cal(data start, data stop){
    return abs(start.nx-stop.sx) + abs(start.ny-stop.sy);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>m>>n>>k>>p;
    first = {1,1,1,1};
    last = {m,n,m,n};
    for(int i = 1; i<=k; ++i){
        cin>>warp[i].sx>>warp[i].sy>>warp[i].nx>>warp[i].ny;
        dp[1][i] = cal(first,warp[i]);
        if(dp[1][i]+cal(warp[i], last) < dis){
            dis = dp[1][i]+cal(warp[i], last);
            pass = 1;
        }
    }
    for(int t = 2; t<=p; ++t){
        for(int i = 1; i<=k; ++i){
            dp[t][i] = 1e9+7;
            for(int j = 1; j<=k; ++j) dp[t][i] = min(dp[t][i], dp[t-1][j]+cal(warp[j], warp[i]));
            if(dp[t][i]+cal(warp[i], last)<dis){
                dis = dp[t][i]+cal(warp[i], last);
                pass = t;
            }
        }
    }
    cout << dis << " " << pass;
}
