#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int n, p, a[N], x;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        int idx = upper_bound(a,a+p,x)-a;
        if(idx==p) p++;
        a[idx]=x;
    }
    cout << n-p << "\n";
}
