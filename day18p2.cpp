#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[30][30][30];
int main(){
    ifstream ifs("in");
    set<tuple<int,int,int>> st;
    string s;
    while(getline(ifs, s)){
        istringstream iss(s);
        int a, b, c; char x;
        iss >> a >> x >> b >> x >> c;
        a++, b++, c++;
        st.insert({a, b, c});
    }
    int ans = 0;
    vis[0][0][0] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    while(q.size()){
        auto &[x, y, z] = q.front(); q.pop();
        for (int dx : {-1, 0, 1})
            for (int dy : {-1, 0, 1})
                for (int dz : {-1, 0, 1}){
                    int a = x + dx, b = y + dy, c = z + dz;
                    if (a < 0 || b < 0 || c < 0 || a > 29 || b > 29 || c > 29) continue;
                    if (abs(a - x) + abs(b - y) + abs(c - z) == 1){
                        if (st.count({a, b, c})) ans++;
                        else if (!vis[a][b][c])
                            vis[a][b][c] = 1, q.push({a, b, c});
                    }
                }
    }
    cout << ans << endl;
}

         

