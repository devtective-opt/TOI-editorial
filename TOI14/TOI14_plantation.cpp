/*
    Author : detective conan
    Problem : TOI14_plantation
    Created : 01/04/2025 21:41 UTC+7 
*/
#include <bits/stdc++.h>
#define HAVE_TESTCASE true
#define conan cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int n, r, d;
vector<pair<int, int>> pos;

bool cmpY(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

double dis(pair<int, int> a, pair<int, int> b){
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x*x + y*y);
}

double find_ans(int l, int r){
    if (r - l == 0) return DBL_MAX;
    if (r - l == 1) return dis(pos[l], pos[r]);
    if (r - l == 2) return min(dis(pos[l], pos[l+1]), min(dis(pos[l+1], pos[l+2]), dis(pos[l], pos[l+2])));
    int mid = l + (r - l)/2;
    double L = find_ans(l, mid), R = find_ans(mid + 1, r);
    double ans = min(L, R);
    vector<pair<int, int>> strip;
    for(int i = l; i <= r; ++i){
        if(abs(pos[i].first - pos[mid].first) < ans) strip.emplace_back(pos[i]);
    }
    sort(strip.begin(), strip.end(), cmpY);
    for(int i = 0; i < strip.size(); ++i){
        for(int j = i + 1; j < strip.size() && abs(strip[i].second - strip[j].second) < ans; ++j){
            ans = min(ans, dis(strip[i], strip[j]));
        }
    }
    return ans;
}

void solve(){
    cin >> n >> r >> d;
    pos.clear();
    pos.resize(n);
    for(int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
    sort(pos.begin(), pos.end());
    if(find_ans(0, n - 1) < d + 2*r) return void(cout << "N\n");
    else cout << "Y\n";
}

int main(){
    conan;
    int t = 1;
    if(HAVE_TESTCASE) cin >> t;
    while(t--) solve();
}
