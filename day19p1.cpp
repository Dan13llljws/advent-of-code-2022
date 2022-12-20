#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<tuple<int,int,int>,int> dp[25][5][21][21][25];
int oc, cc, oco, occ, gco, gcb;
int dfs(int t, int o, int c, int ob, int ro, int rc, int rob, int rg){
    if (t == 24) return 0;
    if (ro > max({oc, cc, oco, gco}) || rc > occ || rob > gcb) return 0;
    if (o >= 30) o = 30;
    if (c >= 40) c = 40;
    if (dp[t][ro][rc][rob][rg].count({o, c, ob})) return dp[t][ro][rc][rob][rg][{o, c, ob}];
    int ret = 0;
    ret = max(ret, dfs(t + 1, o + ro, c + rc, ob + rob, ro, rc, rob, rg));
    if (o >= oc) ret = max(ret, dfs(t + 1, o + ro - oc, c + rc, ob + rob, ro + 1, rc, rob, rg));
    if (o >= cc) ret = max(ret, dfs(t + 1, o + ro - cc, c + rc, ob + rob, ro, rc + 1, rob, rg));
    if (o >= oco && c >= occ) 
        ret = max(ret, dfs(t + 1, o + ro - oco, c + rc - occ, ob + rob, ro, rc, rob + 1, rg));
    if (o >= gco && ob >= gcb) 
        ret = max(ret, dfs(t + 1, o + ro - gco, c + rc, ob + rob - gcb, ro, rc, rob, rg + 1));
    dp[t][ro][rc][rob][rg][{o, c, ob}] = ret + rg;
    return ret + rg;
}
int main(){
    ifstream ifs("in");
    string s;
    int idx = 0;
    auto read = [&](int &x, istringstream& iss, int k){
        string buf;
        for (int i = 0; i < k; i++) iss >> buf;
        iss >> x;
    };
    int ans = 0;
    while(getline(ifs, s)){
        idx++;
        istringstream iss(s);
        read(oc, iss, 6);
        read(cc, iss, 5);
        read(oco, iss, 5);
        read(occ, iss, 2);
        read(gco, iss, 5);
        read(gcb, iss, 2);
        for (int i = 0; i < 25; i++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 21; k++)
                    for (int l = 0; l < 21; l++)
                        for (int m = 0; m < 25; m++)
                            dp[i][j][k][l][m].clear();
        cout << dfs(0, 0, 0, 0, 1, 0, 0, 0) << endl;
        ans += idx * dfs(0, 0, 0, 0, 1, 0, 0, 0);
    }
    cout << ans << endl;
}
