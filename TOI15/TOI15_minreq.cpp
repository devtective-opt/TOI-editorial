#include<bits/stdc++.h>

using namespace std;

int n,m,x,L[11],A[11],qs[10000001],T[11],q[11];
bool ck;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i = 1; i<=n; ++i) cin >> L[i];
    for(int i = 1; i<=n; ++i) cin >> A[i];
    for(int i = 1; i<=m; ++i) cin >> qs[i], qs[i]+=qs[i - 1];
    for(int i = 1; i<=x; ++i) cin >> T[i];
    sort(L+1, L+1+n);
    for(int i = 1; i<=x; ++i){
        for(int j = 0; j<n; ++j) cin >> q[j];
        q[n] = m;
        do{
            ck = true;
            for(int j = 1; j<=n; ++j){
                int cur = q[j - 1], ct = 0;
                while(cur < q[j]){
                    cur = upper_bound(qs + cur, qs + q[j], qs[cur - 1] + L[j] - A[j]) - qs;
                    ct++;
                    if(ct > T[i]){
                        ck = false;
                        break;
                    }
                }
            }
        }while(!ck && next_permutation(A+1, A+1+n));
        ck ? cout << "P\n" : cout << "F\n";
    }
}
