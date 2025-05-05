/*
    Author : detective conan
    Problem : TOI11 candles
    created : 14/03/2025 09:58 UTC+7
*/
#include <bits/stdc++.h>
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define HAVE_TESTCASE false
#define DB(n, s) cout << n << s
#define ANS(n, s) DB(n, s)
#define mod (int)(1e9 + 7)
#define sum(a, b) ((a%mod) + (b%mod))%mod
#define mul(a, b) ((a%mod) * (b%mod))%mod
#define conan cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;
using i64 = int64_t;
using u64 = unsigned i64;
using u32 = unsigned;

const int MAX_N = 2010, MAX_M = 2020;
int n, m, xx[] = {0, 0, -1, 1, 1, 1, -1, -1}, xy[] = {-1, 1, 0, 0, -1, 1, 1, -1}, ans;
bool mp[MAX_N][MAX_M];
char c;

void solve(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> c, mp[i][j] = c - '0';
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(mp[i][j]){
                ++ans;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                mp[i][j] = 0;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    FOR(k, 0, 7){
                        int nx = x + xx[k];
                        int ny = y + xy[k];
                        if(nx < 1 || nx > n || ny < 1 || ny > m || !mp[nx][ny]) continue;
                        mp[nx][ny] = 0;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
    ANS(ans, '\n');
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
