#include<bits/stdc++.h>

using namespace std;

int n,m,pa[3001],p,ans;
vector<tuple<int, int, int>> edge;
vector<int> path;
vector<pair<int, int>> pack;

int fp(int x){
    if(pa[x]==x) return x;
    return pa[x] = fp(pa[x]);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i<=n; ++i) pa[i] = i;
    for(int i = 0; i<m; ++i){
        int u,v,w,st; cin >> u >> v >> w >> st;
        edge.emplace_back(w*(!st),u,v);
    }
    sort(edge.begin(), edge.end());
    for(auto [w,u,v]:edge){
        if(fp(u)!=fp(v)){
            path.push_back(w);
            pa[fp(v)] = fp(u);
        }
    }
    cin >> p;
    while(p--){
        int dt, ct; cin >> dt >> ct;
        pack.emplace_back(ct, dt);
    }
    sort(pack.begin(), pack.end());
    for(auto w:path){
        if(!w) continue;
        for(auto [ct,dt]:pack){
            if(dt > w){
                ans+=ct;
                break;
            }
        }
    }
    cout << ans;
}
