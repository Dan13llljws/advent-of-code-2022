#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    set<pair<int,int>> st;
    vector<pair<int,int>> p(2);
    auto upd = [&](){
        for (int i = 1; i < 2; i++){
            int a = p[i - 1].first, b = p[i - 1].second;
            int x = p[i].first, y = p[i].second;
            if (max(abs(a - x), abs(y - b)) > 1){
                bool f = 0;
                for (int dx : {-1, 0, 1}){
                    for (int dy : {-1, 0, 1})
                        if (max(abs(a - x - dx), abs(b - y - dy)) < 2 && 
                            min(abs(a - x - dx), abs(b - y - dy)) == 0){
                            x = x + dx, y = y + dy, f = 1;
                            break;
                        }
                    if (f) break;
                }
                if (!f){
                    for (int dx : {-1, 0, 1}){
                        for (int dy : {-1, 0, 1})
                            if (max(abs(a - x - dx), abs(b - y - dy)) < 2){
                                x = x + dx, y = y + dy, f = 1;
                                break;
                            }
                        if (f) break;
                    }
                }
            }
            p[i] = {x, y};
        }
        st.insert(p.back());
    };
    while(getline(ifs, s)){
        int t = stoi(s.substr(2));
        if (s[0] == 'U'){
            for (int i = 0; i < t; i++)
                p[0].first++, upd();
        } else if (s[0] == 'D'){
            for(int i = 0; i < t; i++)
                p[0].first--, upd();
        } else if (s[0] == 'L'){
            for (int i = 0; i < t; i++)
                p[0].second--, upd();
        } else {
            for (int i = 0; i < t; i++)
                p[0].second++, upd();
        }
    }
    cout << st.size() << endl;
            
}

