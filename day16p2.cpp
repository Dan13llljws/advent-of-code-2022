#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> adj1[20];
int dp[16][31][1<<16], r[20];

int dfs(int v, int t, int mask){
    if (t < 1) return 0;
    int &ret = dp[v][t][mask];
    if (ret != -1) return ret;
    ret = 0;
    for (auto [w, to] : adj1[v]){
        if (!(mask >> to & 1))
            ret = max(ret, dfs(to, t - w - 1, mask | (1 << to)) + (t - w - 1) * r[to]);
    }
    return ret;
}

int main(){
    ifstream ifs("in");
    map<string,int> dict;
    vector<vector<int>> adj(60);
    vector<int> id(60);
    set<int> good;
    string s;
    int tot = 0, tc = 0;
    while(getline(ifs, s)){
        istringstream iss(s);
        string buf;
        string cur; int f;
        char a, b, c;
        iss >> buf >> cur >> buf >> buf >> c >> c >> c >> c >> c;
        iss >> f >> c >> buf >> buf >> buf >> buf;
        if (!dict.count(cur)) dict[cur] = tot++;
        while(1){
            iss >> a >> b;
            string to = "";
            to.push_back(a), to.push_back(b);
            if (!dict.count(to)) dict[to] = tot++;
            adj[dict[cur]].push_back(dict[to]);
            if (!(iss >> c)) break;
        }
        if (f || cur == "AA"){
            r[id[dict[cur]] = tc++] = f;
            good.insert(dict[cur]);
        }
    }
    for (int src : good){
        vector<int> d(tot);
        queue<int> q;
        q.push(src);
        while(q.size()){
            int p = q.front(); q.pop();
            for (int v : adj[p]){
                if (v != src && !d[v]){
                    d[v] = d[p] + 1, q.push(v);
                    if (good.count(v)){
                        adj1[id[src]].push_back({d[v], id[v]});
                    }
                }
            }
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = 0, n = good.size();
    for (int i = 0; i < (1 << n); i++){
        int ra = dfs(id[dict["AA"]], 26, i);
        int rb = dfs(id[dict["AA"]], 26, (1 << n) - 1 - i);
        ans = max(ans, ra + rb);
    }
    cout << ans << '\n';
}


