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
    int ex = 0, ey = 0;
    vector<vector<int>> d(n, vector<int>(m));
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S' || g[i][j] == 'a'){
                q.push({i, j}), d[i][j] = 1;
            } else if (g[i][j] == 'E'){
                g[i][j] = 'z';
                ex = i, ey = j;
            }
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    auto in = [&](int x, int y){
        return x >= 0 && y >= 0 && x < n && y < m;
    };
    while(q.size()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (in(nx, ny) && g[nx][ny] - g[x][y] < 2 && !d[nx][ny]){
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << d[ex][ey] - 1 << '\n';
}

