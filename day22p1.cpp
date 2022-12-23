#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 200;
int g[MM][MM], l[MM], r[MM], t[MM], b[MM];
int main(){
    ifstream ifs("in");
    memset(l, 0x3f, sizeof l);
    memset(t, 0x3f, sizeof t);
    for (int i = 0; i < 200; i++){
        string s;
        getline(ifs, s);
        for (int j = 0; j < (int)s.size(); j++)
            if (s[j] == '.') g[i][j] = 1;
            else if (s[j] == '#') g[i][j] = 2;
    }
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 150; j++)
            if (g[i][j]){
                l[i] = min(l[i], j);
                r[i] = max(r[i], j + 1);
                t[j] = min(t[j], i);
                b[j] = max(b[j], i + 1);
            }
    string moves;
    ifs >> moves;
    int x = 0, y = l[0], dir = 0;
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int cur = 0;
    for (char c : moves){
        if (isdigit(c)){
            cur = cur * 10 + c - '0';
        } else {
            for (int i = 0; i < cur; i++){
                int nx = x + dx[dir], ny = y + dy[dir];
                nx = (nx - t[y] + b[y] - t[y]) % (b[y] - t[y]) + t[y];
                ny = (ny - l[x] + r[x] - l[x]) % (r[x] - l[x]) + l[x];
                if (g[nx][ny] != 2) x = nx, y = ny;
            }
            if (c == 'R') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            cur = 0;
        }
    }
    for (int i = 0; i < cur; i++){
        int nx = x + dx[dir], ny = y + dy[dir];
        nx = (nx - t[y] + b[y] - t[y]) % (b[y] - t[y]) + t[y];
        ny = (ny - l[x] + r[x] - l[x]) % (r[x] - l[x]) + l[x];
        if (g[nx][ny] != 2) x = nx, y = ny;
    }
    x++, y++;
    cout << 1000 * x + 4 * y + dir << endl;
}

        

