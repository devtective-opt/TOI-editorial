#include<bits/stdc++.h>

using namespace std;

vector<int> vc[100001];
vector<int> level[10001];
int vis[100001];
int cnt;
int curr = -1;

bool dfs(int u){
    if(vis[u] == 2)return false;
    if(vis[u] == 1)return true;
    cnt++;
    vis[u] = 1;
    bool cycle = false;
    for(auto v:vc[u]){
        if(dfs(v)) cycle = true;
    }
    vis[u] = 2;
    return cycle;
}

int main(){
    int n,k,t;
    cin>> n >> k >> t;
    for(int i=1;i<=n;i++){
        int l,p;
        cin>> l >> p;
        level[l].push_back(i);
        for(int j=0;j<p;j++){
            int a;
            cin>> a;
            vc[i].push_back(a);
        }
    }
    for(int i=1;i<=k;i++){
        bool cycle = false;
        for(auto v:level[i]){
            if(dfs(v)) cycle = true;
        }
        if(cnt > t || cycle) break;
        curr = i;
    }
    cout<< curr;
    return 0;
}
