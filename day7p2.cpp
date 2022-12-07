#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    ll ans = 0;
    vector<string> st;
    vector<ll> v, c;
    string cur = "";
    while(getline(ifs, s)){
        if (s[0] == '$'){
            if (s[2] == 'c'){
                cur = s.substr(5);
                if (cur == ".."){
                    ll tmp = v.back();
                    c.push_back(tmp);
                    v.pop_back();
                    v.back() += tmp;
                } else {
                    v.push_back(0);
                }
            } else {
                continue;
            }
        } else {
            if (s[0] == 'd'){
                continue;
            } else {
                ll tmp = 0;
                for (char c : s){
                    if (c == ' ') break;
                    tmp = tmp * 10 + c - '0';
                }
                c.push_back(tmp);
                v.back() += tmp;
            }
        }
    }
    while(v.size()){
        ll tmp = v.back();
        c.push_back(tmp);
        v.pop_back();
        if (v.size()) v.back() += tmp;
    }
    sort(c.begin(), c.end());
    ll x = *c.rbegin() - 4e7;
    cout << *lower_bound(c.begin(), c.end(), x) << '\n';
}

