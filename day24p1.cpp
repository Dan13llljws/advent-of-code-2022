#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> g;
int vis[30][150][5000];
int main(){
    ifstream ifs("in");
    string ss;
    while(getline(ifs, ss)) g.push_back(ss);
    int n = g.size(), m = g[0].size();
    auto check = [&](int x, int y, int t){
        if (x == 0 || x == n - 1) return true;
        for (int i = 1; i < m - 1; i++){
            if (g[x][i] == '<'){
                if (y - 1 == (i - 3 - t % (m - 2) + m) % (m - 2))
                    return false;
            }
            if (g[x][i] == '>'){
                if (y - 1 == (t + i - 1) % (m - 2))
                    return false;
            }
        }
        for (int i = 1; i < n - 1; i++){
            if (g[i][y] == '^'){
                if (x - 1 == (i - 3 - t % (n - 2) + n) % (n - 2))
                    return false;
            }
            if (g[i][y] == 'v'){
                if (x - 1 == (t + i - 1) % (n - 2))
                    return false;
            }
        }
        return true;
    };
    queue<tuple<int,int,int>> q;
    q.push({0, 1, 0});
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    while(q.size()){
        auto [x, y, t] = q.front(); q.pop();
        if (x == n - 1 && y == m - 2){
            cout << t << endl;
            return 0;
        }
        if (!vis[x][y][t + 1] && check(x, y, t + 1))
            vis[x][y][t + 1] = 1, q.push({x, y, t + 1});
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && g[nx][ny] != '#' && !vis[nx][ny][t + 1] && check(nx, ny, t + 1))
                vis[nx][ny][t + 1] = 1, q.push({nx, ny, t + 1});
        }
    }
}

