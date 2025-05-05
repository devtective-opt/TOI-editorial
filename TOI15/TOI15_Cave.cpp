#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> vc[2020];
int dis[2020][5050], n, m, st, en, q;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
vector<pair<int, int>> ans;

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> st >> en >> m, ++st, ++en;
    for(int i = 1; i<=n; ++i) for(int j = 0; j<=n; ++j) dis[i][j] = 1e14;
    for(int i = 0; i<m; ++i){
        int u, v, w; cin >> u >> v >> w, ++u, ++v;
        vc[u].emplace_back(v, w);
    }
    dis[st][0] = 0;
    pq.emplace(0, 0, st);
    while(!pq.empty()){
        int w = get<0>(pq.top()), time = get<1>(pq.top()), u = get<2>(pq.top()); pq.pop();
        if(dis[u][time] < w) continue;
        if(u == en){
            if(!ans.empty() && ans.back().second <= time && ans.back().first <= w) continue;
            ans.emplace_back(w, time);
            continue;
        }
        for(auto x:vc[u]){
            int v = x.first, ww = x.second;
            if(dis[v][time + 1] > w + ww){
                dis[v][time + 1] = w + ww;
                pq.emplace(dis[v][time + 1], time + 1, v);
            }
        }
    }
    cin >> q;
    while(q--){
        int h, mn = 1e14; cin >> h;
        for(auto x:ans) mn = min(mn, x.first + h*(x.second - 1ll));
        cout << mn << ' ';
    }

}
