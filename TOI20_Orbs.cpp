/*
Author : detective conan
Problem : TOI20_orbs
*/
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define int long long
#define FFOR(i, s, t) for (int i = s; i <= t; ++i)
#define FBOR(i, s, t) for (int i = s; i >= t; --i)
#define DB(n, s) cout << n << s
#define ANS(n, s) DB(n, s)
#define mod (int)(1e9 + 7)
#define HAVE_TESTCASE false
#define sum(a, b) ((a + b) % mod)
#define mul(a, b) (((a % mod) * (b % mod)) % mod)
#define N (int)(2e6 + 10)

using namespace std;

int n, l, val[N], s, t;
multiset<int> ms1, ms2;

void solve() {
    cin >> n >> l >> s >> t;
    FFOR(i, 1, n) cin >> val[i];
    sort(val + 1, val + 1 + n);
    FFOR(i, 1, n) {
        if (i > s && i <= t) ms2.insert(val[i]);
        else if (i <= s) ms1.insert(val[i]);
    }
    while (l--) {
        if (ms1.empty() || ms2.empty()) break;
        int a = *(--ms1.end()), b = *(--ms2.end());
        int na = b - a, nb = (a + b) / 2;
        ms1.erase(prev(ms1.end()));
        ms2.erase(prev(ms2.end()));
        int x = min(na, nb), y = max(na, nb);
        if (ms2.empty() || x < *ms2.begin()) ms1.insert(x);
        else {
            ms1.insert(*ms2.begin());
            ms2.erase(ms2.begin());
            ms2.insert(x);
        }
        ms2.insert(y);
    }
    for (auto x : ms1) cout << x << ' ';
    for (auto x : ms2) cout << x << ' ';
    FFOR(i, t + 1, n) cout << val[i] << ' ';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    if (HAVE_TESTCASE) cin >> t;
    while (t--) solve();
}
