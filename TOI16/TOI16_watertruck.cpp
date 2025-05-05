#include<bits/stdc++.h>

using namespace std;

struct data
{
    int u,w;
    bool operator<(const data&d2)const
    {
        return w>d2.w;
    }
};

int n,m,ans;
vector<pair<int, int>> vc[100100],tree[100100],cycle[100100];
int onstack[100100],scc[100100],idx = 1,ct = 0,vis[100100],dis[100100],u,v,w,V,e,pa[100100],dist[100100];
vector<tuple<int, int, int>> edge;
vector<int> trash[100100];
stack<int> s;
map<pair<int, int>, int> edges,ck;

void tarjan(int u, int pa){
    onstack[u] = 1;
    vis[u] = 1;
    dis[u] = scc[u] = idx++;
    s.push(u);
    for(auto [v,w]:vc[u]){
        if(v==pa) continue;
        if(!vis[v]) tarjan(v,u);
        if(onstack[v]) scc[u] = min(scc[u], scc[v]);
    }
    if(dis[u]==scc[u]){
        ++ct;
        while(!s.empty()){
            int v = s.top();
            s.pop();
            scc[v] = ct;
            onstack[v] = 0;
            if(v==u) break;
        }
    }
}

int dijtskra(int ft, int nd){
    for(int i = 0; i<=V*2; ++i) dist[i] = 1e9+7;
    priority_queue<data> pq;
    dist[ft] = 0;
    pq.push({ft,0});
    while(!pq.empty()){
        auto [u,w] = pq.top();
        pq.pop();
        if(dist[u] < w) continue;
        for(auto [v,ww]:vc[u]){
            if(dist[v] > w+ww){
                dist[v] = w+ww;
                pq.push({v,dist[v]});
            }
        }
    }
    return dist[nd];
}

void dfs(int u, int pa){
    for(auto [v,w]:tree[u]){
        if(v==pa) continue;
        ans+=2*w;
        dfs(v,u);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> e >> V;
    for(int i = 0; i<e; ++i){
        cin >> u >> v >> w;
        u++; v++;
        vc[u].emplace_back(v,w);
        vc[v].emplace_back(u,w);
        edge.emplace_back(u,v,w);
    }
    tarjan(1,-1);
    for(auto [u,v,w]:edge){
        if(scc[u]==scc[v]){
            cycle[u].emplace_back(v,w);
            cycle[v].emplace_back(u,w);
            ans+=w;
            continue;
        }
        int a = scc[u], b = scc[v];
        if(edges[{a,b}]) continue;
        edges[{a,b}] = edges[{b,a}] = 1;
        tree[a].emplace_back(b,w);
        tree[b].emplace_back(a,w);
    }
    dfs(1,-1);
    for(int i = 1; i<=V; ++i){
        if(cycle[i].size()==3) trash[scc[i]].emplace_back(i);
    }
    for(int i = 1; i<=ct; ++i){
        if(trash[i].empty()) continue;
        if(trash[i].size()==2){
            ans+=dijtskra(trash[i][0], trash[i][1]);
            continue;
        }
        int mn = 1e9+7;
        for(int j = 1; j<trash[i].size(); ++j){
            vector<int> subtrash;
            for(int k = 1; k < 4; k++){
                if(j == k) continue;
                subtrash.push_back(trash[i][k]);
            }
            int d1 = dijtskra(trash[i][0], trash[i][j]);
            int d2 = dijtskra(subtrash[0], subtrash[1]);
            mn = min(mn, d1 + d2);
        }
        ans+=mn;
    }
    cout << ans;
}
