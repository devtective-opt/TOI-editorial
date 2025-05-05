#include<bits/stdc++.h>

using namespace std;

bitset<2001> imap[10001],imp[10001];
int xx[]={0,0,-1,1};
int xy[]={-1,1,0,0};
char ss;
queue<pair<int, int>> q;
int m,n,p,s,c;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin>>ss;
            if(ss=='0') imap[i][j] = false,imp[i][j] = false;
            else imap[i][j] = true,imp[i][j] = true;
        }
    }
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(imap[i][j]==true){
                q.push({i,j});
                int x1 = i,x2 = i,y1 = j,y2 = j;
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    for(int i = 0; i<4; ++i){
                        int nx = x+xx[i];
                        int ny = y+xy[i];
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(imap[nx][ny]==false) continue;
                        imap[nx][ny] = false;
                        x1 = max(nx,x1),x2 = min(nx,x2),y1 = max(ny,y1),y2 = min(ny,y2);
                        q.push({nx,ny});
                    }
                }
                if(x1-x2==y1-y2){
                    if(imp[(x1+x2)/2+1][y2]==false) s++;
                    else p++;
                }else c++;
            }
        }
    }
    cout<<p<<" "<<s<<" "<<c;
}
