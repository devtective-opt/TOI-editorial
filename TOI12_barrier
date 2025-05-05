#include<bits/stdc++.h>

using namespace std;

int n,k,qs[6000001], ans = -1e9, l = 1e9;
deque<int> dq;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i<=n; ++i){
        cin >> qs[i];
        qs[i]+=qs[i - 1];
    }
    dq.push_back(0);
    for(int i = 1; i<=n; ++i){
        while(!dq.empty() && i - dq.front() > k) dq.pop_front();
        while(!dq.empty() && qs[i] < qs[dq.back()]) dq.pop_back();
        dq.push_back(i);
        int val = qs[i] - qs[dq.front()];
        if(ans < val){
            ans = val;
            l = i - dq.front();
        }
        else if(ans == val && l > i - dq.front()) l = i - dq.front();
    }
    if(ans < 0) cout << 0 << '\n' << 0;
    else cout << ans << '\n' << l;
}
