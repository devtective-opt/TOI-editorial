/*
    Author : detective conan
    Problem : TOI19_jewerly
    Created : 18/03/2025 14_54 UTC+7
*/
#include <bits/stdc++.h>
#define int long long
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define HAVE_TESTCASE false
#define mod (int)(1e9 + 7)
#define DB(n, s) cout << n << s 
#define ANS(n, s) DB(n, s);
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define ph push
#define pf push_front
#define em emplace

using namespace std;
using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned i64;

int n, sum, mxT, ans;
string s;
stack<pair<int, int>> stk;

void solve(){
    cin >> n >> s;
    s = " " + s;
    stk.em(n, 0);
    FOR(i, 1, n){
        if(s[i] == 'F'){
            rep(j, mxT, 1) stk.em(j, i - j);
            ans += sum, mxT = 0;
        }
        else{
            mxT++;
            while(!stk.empty() && mxT > stk.top().first) stk.pop();
            sum += (i - stk.top().second);
            ans += sum;
        }
    }
    ANS(ans, '\n');
}   

int32_t main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
