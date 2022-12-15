#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s, t;
    const int MM = 4e6;
    vector<vector<pair<ll,ll>>> p(MM + 1);
    while(ifs >> s >> s >> s >> t){
        s.pop_back(), t.pop_back();
        int x = stoi(s.substr(2));
        int y = stoi(t.substr(2));
        ifs >> s >> s >> s >> s >> s >> t;
        s.pop_back();
        int a = stoi(s.substr(2));
        int b = stoi(t.substr(2));
        int d = abs(x - a) + abs(y - b);
        for (int i = x - d; i <= x + d; i++){
            if (i < 0) continue;
            if (i > MM) continue;
            int rem = d - abs(x - i);
            int l = y - rem, r = y + rem;
            p[i].push_back({l, -1});
            p[i].push_back({r + 1, 1});
        }
    }
    for (int i = 0; i <= MM; i++){
        sort(p[i].begin(), p[i].end());
        p[i].push_back({4000000, 1});
        int prev = -1, cnt = 0;
        for (auto [pos, v] : p[i]){
            cnt += v, prev = pos;
            if (pos > MM) break;
            if (cnt == 0){
                cout << 1LL * i * 4000000 + pos << endl;
                return 0;
            }
        }
    }
}


