#include<bits/stdc++.h>

using namespace std;

int h[200001],n,q,bf[200001],af[200001],bb,aa,dpl[200001],dpr[200001];
vector<int> ans;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 0; i<n; i++) cin >> h[i];
    for(int i = 0; i<n; i++){
        int idx = lower_bound(af,af+aa,h[i])-af;
        if(idx==aa) aa++;
        af[idx] = h[i];
        dpl[i] = idx;
    }
    for(int i = n-1; i>=0; --i){
        int idx = lower_bound(bf,bf+bb,h[i])-bf;
        if(idx==bb) bb++;
        bf[idx] = h[i];
        dpr[i] = idx;
    }
    while(q--){
        int a; cin>>a;
        cout << min(dpl[a],dpr[a])<<"\n";
    }

}
