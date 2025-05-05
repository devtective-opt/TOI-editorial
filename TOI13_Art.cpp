#include<bits/stdc++.h>

using namespace std;

int n, t, fw[1000100], idx, ans;

void update(int idx, int val){
    for(; idx <= 1e6; idx+=(idx&-idx)) fw[idx]+=val;
}

int query(int idx){
    int sum = 0;
    for(; idx > 0 ; idx-=(idx&-idx)) sum+=fw[idx];
    return sum;
}

int find(int m){
    int l = 1, r = 1e6, ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(query(mid) <= m) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

vector<tuple<int, int, int, int>> vc;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 1; i<=n; ++i){
        int s, h, w, o; cin >> s >> h >> w >> o;
        vc.emplace_back(s, h, w, o);
        vc.emplace_back(s + w, h, w, -o);
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < 2*n - 1; ++i){
        int pos = get<0>(vc[i]), h = get<1>(vc[i]), w = get<2>(vc[i]), o = get<3>(vc[i]);
        update(1, o);
        update(h+1, -o);
        ans += (get<0>(vc[i + 1]) - pos) * (find(t - 1) - find(t));
    }
    cout << ans;
}
