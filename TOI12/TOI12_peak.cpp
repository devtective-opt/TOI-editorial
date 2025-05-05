#include <bits/stdc++.h>

using namespace std;

int arr[5000010];
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++){
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ans.push_back(arr[i]);
    }
    if (ans.empty()){
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    if (ans.size() >= k) reverse(ans.begin(), ans.end());
    for (int i = 0; i < min(int(ans.size()), k); i++) cout << ans[i] << '\n';
    return 0;
}
