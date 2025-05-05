#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9+7;
vector<int> vc[500001];
int n,arr[1000010], vis[500010], fac[500001], ans = 1;
queue<int> q;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i<=2*n - 1; ++i) cin >> arr[i];
    for(int i = 1; i<=2*n - 2; ++i) vc[arr[i]].push_back(arr[i+1]);
    fac[0] = 1;
    for(int i = 1; i<=n; ++i){
        fac[i] = fac[i-1]*i;
        fac[i]%=mod;
    }
    for(int i = 1; i<=n; ++i){
        if(i ==arr[1]) ans*=(fac[vc[i].size()]);
        else ans*=(fac[vc[i].size() - 1]);
        ans%=mod;
    }
    cout << ans;
}
