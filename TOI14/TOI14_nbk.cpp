#include <bits/stdc++.h>

using namespace std;

int n, q;
pair<int, int> p[100001];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> p[i].first;
        p[i].first += p[i-1].first;
        p[i].second = i;
    }
    sort(p+1, p+n+1);
    for(int i = 1; i <= n; ++i){
        p[i].second = max(p[i].second, p[i-1].second);
        v.push_back(p[i].first);
    }
    while(q--){
        int l; cin >> l;
        int k = upper_bound(v.begin(), v.end(), l)-v.begin();
        cout << p[k].second << '\n';
    }
    return 0;
}
