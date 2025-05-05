#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    queue<char> s,sw;
    char ss;
    int n; cin >> n;
    for(int i = 0; i<n; ++i){
        cin >> ss;
        s.push(ss);
        sw.push(ss);
    }
    int i = 1;
    for(int i = 1; i<n; ++i){
        s.push(s.front());
        s.pop();
        if(n%i==0 && s==sw){
            cout << i;
            return 0;
        }
    }
    cout << n;
}
