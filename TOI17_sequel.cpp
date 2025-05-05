#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int qs[321][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int k=1; k<=320; k++) for(int j=1; j<=n; j++) qs[k][j] += qs[k][max(0, j-k)] + arr[j];
    while(q--) {
        int ans=0;
        int l, m, r; cin >> l >> m >> r;
        if(m<=320) ans += qs[m][(r-l)/m * m + l] - qs[m][max(0, l-m)];
        else {
            for(int i=l; i<=r; i+=m) ans += arr[i];
        }
        cout << ans << " ";
    }
    return 0;
}
