#include<bits/stdc++.h>

using namespace std;

int seg[3000001], n, a, ans;

void update(int idx, int val, int l, int r, int node){
    if(l==r){
        seg[node] = max(seg[node], val);
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) update(idx, val, l, mid, node*2);
    else update(idx, val, mid+1, r, node*2+1);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

int query(int l, int r, int L, int R, int node){
    if(R < l || L > r) return 0;
    if(L >= l && R <= r) return seg[node];

    int mid = (L+R)>>1;
    return max(query(l, r, L, mid, node*2), query(l, r, mid+1, R, node*2+1));
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> a;
        int cal = query(1, a, 1, 1000000, 1) + 1;
        ans = max(ans, cal);
        update(a, cal, 1, 1000000, 1);
    }
    cout << n - ans;
}
