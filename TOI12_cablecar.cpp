#include <bits/stdc++.h>

using namespace std;

int group[2501];
int find_group(int n) {
	return group[n]==n ? n : find_group(group[n]);
}

struct edge {
	int u,v,w;
	bool operator<(const edge& a) const {return w>a.w;}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) group[i] = i;
	vector<edge> vec(m);
	for(auto& i:vec) {
		cin >> i.u >> i.v >> i.w;
		i.w--;
	}
	sort(vec.begin(), vec.end());
	int s,d,p; cin >> s >> d >> p;
	for(auto i:vec) {
		int u=find_group(i.u),v=find_group(i.v);
		if (u==v) continue;
		group[u] = v;
		if (find_group(s)==find_group(d)) {
			cout << (p+i.w-1)/i.w;
			return 0;
		}
	}
}
