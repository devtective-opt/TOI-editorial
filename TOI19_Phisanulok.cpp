#include<bits/stdc++.h>

using namespace std;

struct data
{
    int u,w;
    bool operator<(const data&d2)const{
        return w>d2.w;
    }
};

int n,s,dp[(1<<19)+5],ans = -1;
vector<pair<int, int>> vc[(1<<19)+5];
vector<int> node;
priority_queue<data> pq;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>s;
    while(n--){
        int w; cin>>w;
        int u = 0, v = 0;
        for(int i = 0; i<s; ++i){
            int x; cin>>x;
            if(x==-1) u|=(1<<i);
            else if(x==1) v|=(1<<i);
        }
        vc[u].push_back({v,w});
        node.push_back(u);
    }
    for(int i = 1; i<(1<<s); ++i){
        for(int j = 0; j<s; ++j){
            if(i&(1<<j)){
                vc[i].push_back({i^(1<<j), 0});
            }
        }
    }
    for(int i = 0; i<(1<<s); ++i) dp[i] = 1e9+7;
    dp[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [u,w] = pq.top();
        pq.pop();
        for(auto [v,ww]:vc[u]){
            if(dp[v]>w+ww){
                dp[v] = w+ww;
                pq.push({v,dp[v]});
            }
        }
    }
    for(auto u:node){
        ans = max(ans, dp[u]==1e9+7 ? 0:dp[u]);
     }
    cout<<ans;
}
