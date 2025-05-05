#include<bits/stdc++.h>

using namespace std;

struct data
{
    int l,r,i;
    bool operator<(const data&d2)const{
        if(r==d2.r) return l<d2.l;
        return r<d2.r;
    }
};

vector<data> vc;
int n,ans[400001],dp[400001],p;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i<=n; ++i){
        int l,r; cin>>l>>r;
        vc.push_back({-l,r,i});
    }
    sort(vc.begin(), vc.end());
    for(auto [l,r,i]:vc){
        int idx = upper_bound(dp, dp+p, l)-dp;
        if(idx==p) ++p;
        dp[idx] = l;
        ans[i] = idx+1;
    }
    cout<<p<<"\n";
    for(int i = 1; i<=n; ++i) cout<<ans[i]<<" ";
}
