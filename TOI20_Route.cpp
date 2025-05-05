#include<bits/stdc++.h>

using namespace std;

vector<int> vc;
int n, m;

vector<pair<int, int>> route(int n, vector<int> W){
    vector<pair<int, int>> ans;
    int cnt = 0;
    for(int i = 1; i<=n; ++i){
        if(cnt){
            if(i == n) ans.emplace_back(i, 1);
            else ans.emplace_back(i, i+1);
            continue;
        }
        for(int j = 1; j<i; ++j){
            ans.emplace_back(j, i);
            if(ans.size() == W.size() - (n - i)){
                cnt = 1;
                break;
            }
        }
    }
    return ans;
}

/*int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    vc.resize(m);
    for(int i = 0; i<m; ++i) cin >> vc[i];
    vector<pair<int, int>> ans = route(n, vc);
    for(int i = 0; i<ans.size(); ++i){
        cout << ans[i].first << ' ' << ans[i].second << ' ' << vc[i] << '\n';
    }
}*/
