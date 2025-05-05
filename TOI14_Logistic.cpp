#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, u, v, w, s ,e, lim, pay[101];
ll dis[2][101][101];
vector<pair<int,int>> vc[101];

struct DATA{
    int now, oil, use, w;
    bool operator < (const DATA & d2) const{
        return w > d2.w;
    }
};

priority_queue<DATA>pq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(dis,127,sizeof dis);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> pay[i];
    cin >> s >> e >> lim >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        vc[u].push_back({v,w});
        vc[v].push_back({u,w});
    }
    pq.push({s,0,0,0});
    dis[0][0][s]=0;
    while(!pq.empty()){
        auto [now,oil,use,noww] = pq.top();
        pq.pop();
        if(!use && dis[1][lim][now]>noww){
            dis[1][lim][now]=noww;
            pq.push({now,lim,1,noww});
        }
        if(oil<lim && dis[use][oil+1][now]>noww+pay[now]){
            dis[use][oil+1][now]=noww+pay[now];
            pq.push({now,oil+1,use,noww+pay[now]});
        }
        for(auto [x,w] : vc[now]){
            if(oil>=w && dis[use][oil-w][x]>noww){
                dis[use][oil-w][x]=noww;
                pq.push({x,oil-w,use,noww});
            }
        }
    }
    cout<<min(dis[1][lim][e], dis[0][lim][e]);
}
