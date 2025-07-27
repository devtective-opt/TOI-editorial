/*
    Author : detective conan
    Problem : duty free 
    Created : 22/06/2025 22:45 UTC+7
*/
#include <bits/stdc++.h>
#define FOR(i, s, t) for(int i = s; i <= t; ++i)
#define rep(i, s, t) for(int i = s; i >= t; --i)
#define FPOR(i, s, t, c) for(int i = s; i <= t; i += c)
#define rmep(i, s, t, c) for(int i = s; i >= t; i -= c)
#define FMOR(i, s, t, c) for(int i = s; i <= t; i *= c)
#define rdep(i, s, t, c) for(int i = s; i >= t; i /= c)
#define HAVE_TESTCASE false
#define ANS(n, s) cout << (n) << (s)
#define pii pair<i64, i64>
#define tiii tuple<i64, i64, i64>
#define P pair
#define T tuple
#define vec vector
#define all(a) a.begin(), a.end()
#define great(a) a, vec<a>, greater<a>
#define F first
#define S second
#define pout(n) cout << n.F << ' ' << n.S << '\n';
#define conan cin.tie(nullptr)->sync_with_stdio(false)
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lbv(a, m) lower_bound(all(a), m) - a.begin()
#define upv(a, m) upper_bound(all(a), m) - a.begin()
#define lb lower_bound
#define ub upper_bound
#define sz(n) n.size()

using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int fp(int n, vec<int> &pa, vec<int> &lvl, int last, int i) {
	if (lvl[n] <= last) {
		lvl[n] = i;
		pa[n] = n;
	}
	if (pa[n] == n) return n;
	return pa[n] = fp(pa[n], pa, lvl, last, i);
}

int minimum_bag_rearrangement_time(vec<int> max_allowed_positions) {
	vec<int> vc = max_allowed_positions, pa(sz(vc) + 1, 0), lvl(sz(vc) + 1, -1);
	int n = sz(vc), ans = 0, last = -1;
	iota(all(pa), 0);
	vc.insert(vc.begin(), 0);
	FOR(i, 1, n) {
		int x = fp(vc[i], pa, lvl, last, i);
		if (x == 0) {
			++ans;
			last = i - 1;
			x = fp(vc[i], pa, lvl, last, i);
		}
		pa[x] = fp(x - 1, pa, lvl, last, i);
	}
	return ans;
}