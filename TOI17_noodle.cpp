#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k, noodle[100100], l = 1, r = 1e12, ans;

bool solve(int mid){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0, cnt = 0;
    for(int i = 1; i<=n; ++i){
        sum+=noodle[i];
        pq.push(noodle[i]);
        if(pq.size() > k){
            sum-=pq.top();
            pq.pop();
        }
        if(sum >= mid && pq.size() == k){
            cnt++;
            sum = 0;
            while(!pq.empty()) pq.pop();
        }
    }
    return cnt >= m;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i<=n; ++i) cin >> noodle[i];
    while(l <= r){
        int mid = (l + r) >> 1;
        if(solve(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans;
}
