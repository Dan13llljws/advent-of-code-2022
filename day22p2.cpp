#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 200;
int g[MM][MM], l[MM], r[MM], t[MM], b[MM];
int main(){
    ifstream ifs("in");
    freopen("out2", "w", stdout);
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
    auto upd = [&](){
        for (int i = 0; i < cur; i++){
            int nx = x + dx[dir], ny = y + dy[dir], nd = dir;
            if (nx < 0 || ny < 0 || nx >= 200 || ny >= 150 || !g[nx][ny]){
                if (nx < 0){
                    if (y < 100) nd = 0, nx = y + 100, ny = 0;
                    else nd = 3, nx = 199, ny = y - 100;
                } else if (nx < 50){
                    if (y < 100) nd = 0, nx = 149 - x, ny = 0;
                    else nd = 2, nx = 149 - x, ny = 99;
                } else if (nx < 100){
                    if (x < 50) nd = 2, nx = y - 50, ny = 99;
                    else if (x > 99) nd = 0, nx = y + 50, ny = 50;
                    else if (dir == 2) nd = 1, nx = 100, ny = x - 50;
                    else nd = 3, nx = 49, ny = x + 50;
                } else if (nx < 150){
                    if (y < 50) nd = 0, nx = 149 - x, ny = 50;
                    else nd = 2, nx = 149 - x, ny = 149;
                } else if (nx < 200){
                    if (x < 150) nd = 2, nx = y + 100, ny = 49;
                    else if (dir == 2) nd = 1, nx = 0, ny = x - 100;
                    else nd = 3, nx = 149, ny = x - 100;
                } else nd = 1, nx = 0, ny = y + 100;
            }
            if (g[nx][ny] != 2) x = nx, y = ny, dir = nd;
        }
    };
    for (char c : moves){
        if (isdigit(c)){
            cur = cur * 10 + c - '0';
        } else {
            upd();
            if (c == 'R') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            cur = 0;
        }
    }
    upd();
    x++, y++;
    cout << 1000 * x + 4 * y + dir << endl;
}
