#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    vector<string> g;
    while(getline(ifs, s)){
        g.push_back(s);
    }
    int n = g.size(), m = g[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            int f = 0, ff = 1;
            for (int i1 = i - 1; i1 >= 0; i1--){
                if (g[i1][j] >= g[i][j]) ff = 0;
            }
            f |= ff, ff = 1;
            for (int i1 = i + 1; i1 < n; i1++){
                if (g[i1][j] >= g[i][j]) ff = 0;
            }
            f |= ff, ff = 1;
            for (int j1 = j - 1; j1 >= 0; j1--){
                if (g[i][j1] >= g[i][j]) ff = 0;
            }
            f |= ff, ff = 1;
            for (int j1 = j + 1; j1 < m; j1++){
                if (g[i][j1] >= g[i][j]) ff = 0;
            }
            f |= ff, ff = 1;
            ans += f;
        }
    cout << ans << '\n';
}

