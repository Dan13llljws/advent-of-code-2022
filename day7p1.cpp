#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    ll ans = 0;
    vector<string> st;
    vector<ll> v;
    string cur = "";
    while(getline(ifs, s)){
        if (s[0] == '$'){
            if (s[2] == 'c'){
                cur = s.substr(5);
                if (cur == ".."){
                    if (v.back() <= 1e5) ans += v.back();
                    ll tmp = v.back();
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
                v.back() += tmp;
            }
        }
    }
    while(v.size()){
        ll tmp = v.back();
        if (tmp <= 1e5) ans += tmp;
        v.pop_back();
        if (v.size()) v.back() += tmp;
    }
    cout << ans << endl;
}

