#include<bits/stdc++.h>

using namespace std;

int odd[10010], even[10010], food, n, v, w, dp[10010];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> v >> w;
    for(int i = 1; i<=n; ++i){
        cin >> food;
        if(food&1) odd[i] = odd[i - 1] + food, even[i] = even[i - 1];
        else odd[i] = odd[i - 1], even[i] = even[i - 1] + food;
    }
    for(int i = 1; i<=n; ++i) dp[i] = 1e9;
    dp[1] = 0;
    for(int i = 1; i<=n; ++i){
        for(int j = i+1; j<=n; j+=2){
            int sz = (j - i + 1)/2, l = i, mid = (j+i)/2, r = j;
            int left = odd[mid] - odd[i - 1], right = even[j] - even[mid];
            if(left <= v && right <= w) dp[j] = min(dp[j], dp[i - 1]+1);
        }
    }
   dp[n] == 1e9 ? cout << -1 : cout << dp[n];
    //for(int i = 1; i<=n; ++i) cout << dp[i] << ' ';
}
