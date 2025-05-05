/*
    Author : detective conan
    Problem : TOI11_place
    created : 14/03/2025 11:06 UTC+7
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

const int MAX_N = 2e5 + 10, MAX_M = 1e6 + 10;
int n, m, u, v, w, pa[MAX_N];
priority_queue<array<int, 3>> pq;
i64 ans;

int fp(int n){
    if(pa[n] == n) return n;
    return pa[n] = fp(pa[n]);
}

void solve(){
    cin >> n >> m;
    iota(pa + 1, pa + 1 + n, 1);
    FOR(i, 1, m){
        cin >> u >> v >> w;
        pq.push({w - 1, u, v});
    }
    while(!pq.empty()){
        int w = pq.top()[0], u = pq.top()[1], v = pq.top()[2];
        pq.pop();
        if(fp(u) != fp(v)){
            pa[fp(u)] = fp(v);
            ans += (i64)w;
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
