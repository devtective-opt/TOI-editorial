#include<bits/stdc++.h>

using namespace std;

char mp[2001][2001],vis[2001][2001],vis2[2001][2001];
int m,n,xx[] = {0,0,-1,1},xy[] = {-1,1,0,0},ans = -1,cc = 0;
queue<pair<int, int>> q;

void solve(int i, int j)
{
    q.push({i,j});
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(vis2[x][y]) continue;
        vis2[x][y] =1;
        for(int i = 0; i<4; ++i){
            int nx = x+xx[i];
            int ny = y+xy[i];
            if(nx<1 || ny<1 || nx>m || ny>n) continue;
            if(mp[nx][ny]=='#'){
                cc++;
            }
        }
        for(int i = 0; i<4; ++i){
            int nx = x+xx[i];
            int ny = y+xy[i];
            if(nx<1 || ny<1 || nx>m || ny>n) continue;
            if(mp[nx][ny]=='X'){
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 1; i<=m; ++i){
        for(int j = 1; j<=n; ++j){
            cin>>mp[i][j];
        }
    }
    q.push({1,1});
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        for(int i = 0; i<4; ++i){
            int ax = x+xx[i];
            int ay = y+xy[i];
            if(ax<1 || ay<1 || ax>m || ay>n || mp[ax][ay]=='X') continue;
            mp[ax][ay] = '#';
            q.push({ax,ay});
        }
    }
    for(int i = 1; i<=m; ++i){
        for(int j = 1; j<=n; ++j){
            if(mp[i][j]=='X'){
                cc = 0;
                solve(i,j);
                ans = max(ans,cc);
            }
        }
    }
    cout<<ans;
}
