#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    map<string,int> dict;
    int tot = 0;
    vector<vector<int>> adj(100);
    vector<int> r(100);
    auto get = [&](string &s){
        if (dict.count(s)) return dict[s];
        return dict[s] = ++tot;
    };
    auto add = [&](string &s){
        s[0] = 'v';
        string cur = "", src = "";
        int rate = 0, f = 0;
        for (char c : s){
            if (c == ';') f = 0;
            if (f) rate = rate * 10 + c - '0';
            if (c >= 'A' && c <= 'Z') cur += c;
            else cur = "";
            if (cur.size() == 2){
                if (src.size()) adj[get(src)].push_back(get(cur));
                else src = cur;
            }
            if (c == '=') f = 1;
        }
        r[get(src)] = rate;
    };
    string s;
    while(getline(ifs, s)){
        add(s);
    }
    vector<unordered_map<ll,int>> dp(tot + 1);
    dp[dict["AA"]][0] = 0;
    for (int i = 1; i <= 30; i++){
        vector<unordered_map<ll,int>> dp1(tot + 1);
        for (int j = 1; j <= tot; j++){
            for (auto [mask, v] : dp[j]){
                if (!(mask >> j & 1) && r[j])
                    dp1[j][mask | (1LL << j)] = max(dp1[j][mask | (1LL << j)], v + r[j] * (30 - i));
                for (int u : adj[j]){
                    dp1[u][mask] = max(dp1[u][mask], v);
                }
            }
        }
        dp = dp1;
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++)
        for (auto [mask, v] : dp[i])
            ans = max(ans, v);
    cout << ans << endl;
}

