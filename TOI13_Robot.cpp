#include<bits/stdc++.h>

using namespace std;

queue<pair<int, pair<int, int>>> q;
int n,m,xx[] = {0,0,-1,1},xy[] = {-1,1,0,0},cc = 0,ll = 0;
string s;
char a[2001][2001];
bool vis[2001][2001];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i<n; ++i){
        cin>>s;
        for(int j = 0; j<m; ++j){
            a[i][j] = s[j];
            if(a[i][j]=='X'){
                q.push({0,{i,j}});
            }
        }
    }
    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if(vis[x][y]) continue;
        if(a[x][y]=='A'){
            cc+=(cnt*2);
            ++ll;
        }
        vis[x][y] = true;
        for(int i = 0; i<4; ++i){
            int nx = xx[i]+x;
            int ny = xy[i]+y;
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(a[nx][ny]=='W') continue;
            q.push({cnt+1,{nx,ny}});
        }
    }
    cout<<ll<<" "<<cc;
    return 0;
}
