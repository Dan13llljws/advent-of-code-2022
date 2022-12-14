#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("in");
    set<pair<int,int>> st;
    string s;
    while(getline(ifs, s)){
        int px = 0, py = 0, x = 0, y = 0, f = 0;
        int cur = 0;
        for (char c : s){
            if (c == '-' || c == ','){
                if (f) y = cur;
                else x = cur;
                f ^= 1, cur = 0;
            } else if (isdigit(c)) {
                cur = cur * 10 + c - '0';
            }
            if (c == '-'){
                if (px || py){
                    for (int i = min(px, x); i <= max(px, x); i++)
                        for (int j = min(py, y); j <= max(py, y); j++)
                            st.insert({i, j});
                }
                px = x, py = y;
            }
        } y = cur;
        for (int i = min(px, x); i <= max(px, x); i++)
            for (int j = min(py, y); j <= max(py, y); j++)
                st.insert({i, j});
    }
    auto check = [&](int x, int y){
        return st.count({x, y});
    };
    auto go = [&](auto self, int x, int y){
        if (y == 200) return 0;
        if (check(x, y + 1) && check(x - 1, y + 1) && check(x + 1, y + 1)){
            st.insert({x, y});
            return 1;
        }
        if (!check(x, y + 1)) return self(self, x, y + 1);
        if (!check(x - 1, y + 1)) return self(self, x - 1, y + 1);
        return self(self, x + 1, y + 1);
    };
    for (int i = 0;; i++){
        if (!go(go, 500, 0)){
            cout << i << endl;
            break;
        }
    }
}
