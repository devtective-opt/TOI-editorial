/*
Author : detective conan
Problem : TOI18_shopping
*/
#include<bits/stdc++.h>
#define int long long
#define FOR(s, t) for(int i = s; i <= t; ++i)
#define db(n) cout << n << '\n';

using namespace std;

const int mod = 1e9 + 7;
const bool HAVE_TESTCASE = false;

int n, m, arr[500500], point[500500], paid[500500];

void solve(){
    cin >> n >> m;
    FOR(1, n){
        cin >> arr[i];
        point[i] = point[i - 1] + (arr[i] >= 0)*abs(arr[i]);
        paid[i] = paid[i - 1] + (arr[i] <= 0)*abs(arr[i]);
    }
    while(m--){
        int x, h; cin >> x >> h, ++x;
        int l = x, r = n, ans = x - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(paid[mid] - paid[x - 1] < h) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << point[ans] - point[x - 1] << '\n';
    }
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
