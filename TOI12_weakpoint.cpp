#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> vc[500001];
bool vis[500001];
int weak=0,pos = 500001;

int dfs(int u,int pa){
    vis[u] = 1;
    bool d =false;
    int sum = 1;
    for(auto v:vc[u]){
        if(v == u || v==pa) continue;
        if(v == m) d = 1;
        if(vis[v]) continue;
        int cnt = dfs(v,u);
        if(cnt==0) d=1;
        sum += cnt;
    }
    if(u != m){
        if(weak == sum){
            pos = min(pos,u);
        }else if(weak < sum){
            weak = sum;
            pos = u;
        }
    }
    if(d) return 0;
    else return sum;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>> n >> m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    dfs(m,0);
    cout<< pos << "\n" << weak-1;
    return 0;
}
