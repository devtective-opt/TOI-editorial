#include<bits/stdc++.h>

using namespace std;

bool dp[1010][1010];
int n, m, k;
string A, B;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> A >> B >> k;
    n = A.size(), m = B.size();
    while(k--){
        string s; cin >> s;
        for(int i = 0; i<=n; ++i) for(int j = 0; j<=m; ++j) dp[i][j] = false;
        dp[0][0] = true;
        for(int i = 0; i<=n; ++i){
            for(int j = 0; j<=m; ++j){
                if(i) dp[i][j] |= (dp[i - 1][j] && (A[i - 1] == s[i+j-1]));
                if(j) dp[i][j] |= (dp[i][j - 1] && (B[j - 1] == s[i+j-1]));
            }
        }
        dp[n][m] ? cout << "Yes\n" : cout << "No\n";
    }
}
