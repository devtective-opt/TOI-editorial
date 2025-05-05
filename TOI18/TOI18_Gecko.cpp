#include<bits/stdc++.h>
#define ll long long
#define N 20005
#define pii pair<ll,ll>

using namespace std;

int n,m,k,p;
vector<pii> adj[N];
ll dist[N],parent[N],gecko[N];

void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[p]=0;
    pq.push({0,p});
    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k >> p;
    for(int i=0;i<k;i++)cin >> gecko[i];
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    fill_n(dist,n+1,LONG_MAX);
    fill_n(parent,n+1,-1);
    dijkstra();
    set<pii> path;
    for(int i=0;i<k;i++){
        cout << dist[gecko[i]] << " ";
        int cur = gecko[i];
        while(parent[cur]!=-1){
            path.insert({cur,parent[cur]});
            cur=parent[cur];
        }
    }
    cout <<"\n"<<path.size() << "\n";
    for(auto x:path) cout << x.first << " " << x.second << "\n";
}
