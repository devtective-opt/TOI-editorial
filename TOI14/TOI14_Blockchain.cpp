#include<bits/stdc++.h>

using namespace std;

int t,q,u,v,n;
map<vector<pair<int, int>>, int> mp;
vector<pair<int, int>> vv;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> t >> q;
    while(t--){
        cin>>n;
        for(int i = 0; i<n-1; ++i){
            cin >> u >> v;
            vv.push_back({u,v});
            vv.push_back({v,u});
        }
        sort(vv.begin(),vv.end());
        mp[vv]++;
        vv.clear();
    }
    while(q--){
        cin >> n;
        for(int i = 0; i < n-1; ++i){
            cin >> u >> v;
            vv.push_back({u,v});
            vv.push_back({v,u});
        }
        sort(vv.begin(),vv.end());
        cout << mp[vv] << "\n";
        vv.clear();
    }
}
