#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct DATA{
    int u; ll w;
    bool operator <(const DATA&d2) const{
        return w>d2.w;
    }
};

int N,M,X,Y,u,v;
ll dist[10001],w,dist2[10001],Z;
vector<pair<int, int>> vc[10001],vv[10001];
priority_queue<DATA> pq;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> X >> Y >> Z;
    for(int i = 0; i<M; ++i){
        cin >> u >> v >> w;
        vc[u].push_back({v,w});
        vc[v].push_back({u,w});
    }
    for(int i = 0; i<=N; ++i) dist[i] = 1e14+1;
    dist[X] = 0;
    pq.push({X,0});
    while(!pq.empty()){
        auto [u,w] = pq.top();
        pq.pop();
        for(auto [v,ww]:vc[u]){
            if(dist[v]>w+ww){
                dist[v] = w+ww;
                pq.push({v,dist[v]});
            }
        }
    }
    if(dist[Y]<=Z){
        cout<<Y<<" "<<dist[Y]<<" "<<0;
        return 0;
    }
    dist2[Y] = 0;
    for(int i = 0; i<N; ++i) dist2[i] =1e14+1;
    pq.push({Y,0});
    while(!pq.empty()){
        auto [u,w] = pq.top();
        pq.pop();
        for(auto [v,ww]:vc[u]){
            if(dist2[v] > w+ww){
                dist2[v] = w+ww;
                pq.push({v, dist2[v]});
            }
        }
    }
    ll mn = 2e14+1, rdist = 0, cnt = 0;
    int node;
    for(int i = 0; i<N; ++i){
        if(dist[i] <= Z && dist2[i] < mn){
            mn = dist2[i];
            node = i;
        }
    }
    cout << node << " " << dist[node] << " " << mn;
}
