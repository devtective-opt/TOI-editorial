#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, input, m = 0;
    stack<int> s;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(s.empty()) s.push(input);
        else if(s.top() == input) s.pop();
        else if(input > s.top()){
            m = max(m, s.top());
            s.push(input);
        }
        else m = max(m, input);
    }
    cout << m;
}
