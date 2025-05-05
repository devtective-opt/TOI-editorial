#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 15005;
pair<int,int> p[mxN];
int n,k;
int dis[mxN];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>> n >> k;
    for(int i=0;i<n;i++) cin>> p[i].first >> p[i].second;
    memset(dis , 32 , sizeof(dis));
    for(int i=0;i<n;i++){
        int mn = INT_MAX;
        int idx;
        for(int j=i+1;j<n;j++){
            int d = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
            dis[j] = min(dis[j] , d);
            if(mn > dis[j]){
                mn = dis[j];
                idx = j;
            }
        }
        swap(dis[i+1] , dis[idx]);
        swap(p[i+1] , p[idx]);
    }
    sort(dis , dis+n+1);
    ll sum = 0;
    for(int i=0;i<n-k;i++) sum += dis[i];
    cout<< sum;
    return 0;
}
