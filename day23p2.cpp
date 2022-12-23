#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    vector<string> g;
    string s;
    while(getline(ifs, s))
        g.push_back(s);
    int n = g.size(), m = g[0].size();
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '#') st.insert({i, j});
    vector<vector<int>> dx = {{-1, -1, -1},
                              {1, 1, 1},
                              {-1, 0, 1}, 
                              {-1, 0, 1}},
                        dy = {{-1, 0, 1},
                              {-1, 0, 1},
                              {-1, -1, -1},
                              {1, 1, 1}};
    auto check = [&](int x, int y, int id){
        for (int i = 0; i < 3; i++)
            if (st.count({x + dx[id][i], y + dy[id][i]})) return false;
        return true;
    };
    for (int i = 0;; i++){
        map<pair<int,int>,int> c1;
        set<pair<int,int>> nst;
        for (auto [x, y] : st){
            int c = 0;
            for (int j = 0; j < 4; j++) c += check(x, y, j);
            if (c % 4 == 0) nst.insert({x, y});
            else {
                for (int j = i; j < i + 4; j++)
                    if (check(x, y, j % 4)){
                        c1[{x + dx[j % 4][1], y + dy[j % 4][1]}]++;
                        break;
                    }
            }
        }
        for (auto [x, y] : st){
            if (nst.count({x, y})) continue;
            for (int j = i; j < i + 4; j++){
                int k = j % 4;
                if (check(x, y, k)){
                    if (c1[{x + dx[k][1], y + dy[k][1]}] == 1)
                        nst.insert({x + dx[k][1], y + dy[k][1]});
                    else nst.insert({x, y});
                    break;
                }
            }
        }
        bool f = 0;
        for (auto [x, y] : nst){
            if (!st.count({x, y})){
                f = 1;
                break;
            }
        }
        if (!f){
            cout << i + 1 << endl;
            break;
        }
        st = nst;            
    }
}
