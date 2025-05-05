#include<bits/stdc++.h>

using namespace std;

int n,ht[500001],medal[500001],arm[500001];
long long ans;

int main(){
    cin >> n;
    for(int i = 0; i<n; ++i) cin>>ht[i];
    for(int i = 0; i<n; ++i) cin>>medal[i];
    sort(ht,ht+n); sort(medal,medal+n);
    reverse(ht,ht+n);
    for(int i = 0; i<n; ++i){
        arm[i] = medal[i]+ht[i];
    }
    sort(arm,arm+n);
    for(int i = 1; i<n; ++i){
        ans+=(arm[i]-arm[i-1]);
    }
    cout<<ans;
}
