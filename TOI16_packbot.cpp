#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    stack <char> stk_oper;
    vector <int> postfix;
    for (auto c : s) {
        if (c >= 'A' and c <= 'Z') postfix.push_back(20);
        else if (c == '[') stk_oper.push(c);
        else if (c == ']') {
            while (!stk_oper.empty() and stk_oper.top() != '[') {
                postfix.push_back(stk_oper.top() - 48);
                stk_oper.pop();
            }
            stk_oper.pop();
        }
        else if (c >= '1' and c <= '3') {
            while (!stk_oper.empty() and stk_oper.top() >= c and stk_oper.top() != '[') {
                postfix.push_back(stk_oper.top() - 48);
                stk_oper.pop();
            }
            stk_oper.push(c);
        }
    }
    while (!stk_oper.empty()) {
        postfix.push_back(stk_oper.top() - 48);
        stk_oper.pop();
    }
    stack <int> stk;
    for (auto v : postfix) {
        if (v >= 1 and v <= 3) {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();

            if (v == 1) stk.push(a + b + (a + b) * 4 / 100);
            else if (v == 2) stk.push(a + b + (a + b) * 8 / 100);
            else if (v == 3) stk.push(a + b + (a + b) * 16 / 100);
        }
        else stk.push(v);
    }
    cout << stk.top();
    return 0;
}
