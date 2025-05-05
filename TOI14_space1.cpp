#include<bits/stdc++.h>

using namespace std;

int xx[]={0,0,-1,1};
int xy[]={-1,1,0,0};
int n,m,p,s,c;
string imap[1001],iimp[1001],impp[1001];
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i<m; ++i){
        cin>>imap[i];
        iimp[i] = imap[i];
        impp[i] = imap[i];
    }
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if(imap[i][j]=='1'){
                q.push({i,j});
                int x1 = i,x2 = i,y1 = j,y2 = j,mid;
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    for(int i = 0; i<4; ++i){
                        int nx = x+xx[i];
                        int ny = y+xy[i];
                        if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                        if(imap[nx][ny]=='0') continue;
                        imap[nx][ny] = '0';
                        x1 = max(nx,x1),x2 = min(nx,x2),y1 = max(ny,y1),y2 = min(ny,y2);
                        q.push({nx,ny});
                    }
                }
                if(x1-x2==y1-y2){
                    if(impp[(x1+x2)/2+1][y2]=='0') s++;
                    else p++;
                }else c++;
            }
        }
    }
    cout<<p<<" "<<s<<" "<<c;
}
