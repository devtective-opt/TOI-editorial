#include<bits/stdc++.h>
 
using namespace std;
 
vector<tuple<int, int, int>> pos;
int n, fw[400400], ans[400400], l, r;
vector<int> R;
 
void upd(int idx, int val){
    for(int i = idx; i <= n; i += (i&-i)) fw[i] = max(fw[i], val);
}
 
int qry(int idx){
    int sum = -1;
    for(int i = idx; i > 0; i -= (i&-i)) sum = max(sum, fw[i]);
    return sum;
}
 
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> l >> r, pos.emplace_back(l, r, i), R.push_back(r);
    sort(pos.begin(), pos.end(), cmp);
    sort(R.begin(), R.end());
    R.erase(unique(R.begin(), R.end()), R.end());
    for(int i = pos.size() - 1; i >= 0; --i){
        int l = get<0>(pos[i]), r = get<1>(pos[i]), p = get<2>(pos[i]);
        int idx = lower_bound(R.begin(), R.end(), r) - R.begin();
        ans[p] = qry(idx + 1) + 1;
        upd(idx + 1, ans[p]);
    }
    cout << *max_element(ans + 1, ans + 1 + n) << '\n';
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
