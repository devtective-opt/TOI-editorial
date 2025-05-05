#include<bits/stdc++.h>

using namespace std;

int n,m,q,cost[501],dis[501][501],cnt[501][501];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1; i<=n; ++i) cin >> cost[i];
    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if(i==j) continue;
            dis[i][j] = cost[i]+cost[j];
            cnt[i][j] = 2;
        }
    }
    for(int i = 0; i<m; ++i){
        int ft,nd,ct; cin >> ft >> nd >> ct;
        dis[ft][nd] = dis[nd][ft] = min(dis[ft][nd],ct);
        cnt[ft][nd] = 2;
    }
    for(int k = 1; k<=n; ++k){
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=n; ++j){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    cnt[i][j] = cnt[i][k]+cnt[k][j];
                }
                if(dis[i][j] == dis[i][k]+dis[k][j]){
                    cnt[i][j] = max(cnt[i][j], cnt[i][k]+cnt[k][j]);
                }
            }
        }
    }
    while(q--){
        int u,v; cin >> u >> v;
        cout << dis[u][v] << " " << cnt[u][v] << "\n";
    }
}
