#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
int l[MM], r[MM], vis[MM]; ll v[MM]; char o[MM];
int main(){
    ifstream ifs("in");
    map<string,int> dict;
    int tot = 0;
    string s;
    auto get = [&](string str){
        if (!dict.count(str)) dict[str] = tot++;
        return dict[str];
    };
    memset(l, -1, sizeof l); memset(r, -1, sizeof r);
    while(ifs >> s){
        s.pop_back();
        string a, b, op;
        ifs >> a;
        if (isdigit(a[0])){
            v[get(s)] = stoi(a);
        } else {
            ifs >> op >> b;
            l[get(s)] = get(a);
            o[get(s)] = op[0];
            r[get(s)] = get(b);
        }
    }
    auto dfs = [&](auto self, int src){
        if (l[src] == -1) return v[src];
        if (vis[src]) return v[src];
        v[src] = 1;
        if (o[src] == '+') v[src] = self(self, l[src]) + self(self, r[src]);
        if (o[src] == '-') v[src] = self(self, l[src]) - self(self, r[src]);
        if (o[src] == '*') v[src] = self(self, l[src]) * self(self, r[src]);
        if (o[src] == '/') v[src] = self(self, l[src]) / self(self, r[src]);
        return v[src];
    };
    cout << dfs(dfs, get("root")) << endl;
}
