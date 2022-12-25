#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    ll sum = 0;
    string s;
    auto to_dec = [&](string s){
        ll ret = 0;
        for (char c : s){
            if (c == '-') ret = ret * 5 - 1;
            else if (c == '=') ret = ret * 5 - 2;
            else ret = ret * 5 + c - '0';
        }
        return ret;
    };
    auto to_snafu = [&](ll x){
        string ret;
        while(x){
            if (x % 5 == 4) x -= -1, ret.push_back('-');
            else if (x % 5 == 3) x -= -2, ret.push_back('=');
            else ret.push_back(x % 5 + '0');
            x /= 5;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };
    while(getline(ifs, s)){
        sum += to_dec(s);
    }
    cout << to_snafu(sum) << endl;
}
