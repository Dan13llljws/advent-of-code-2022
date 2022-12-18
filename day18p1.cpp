#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    set<tuple<int,int,int>> st;
    string s;
    while(getline(ifs, s)){
        istringstream iss(s);
        int a, b, c; char x;
        iss >> a >> x >> b >> x >> c;
        st.insert({a, b, c});
    }
    int ans = st.size() * 6;
    for (auto [x, y, z] : st){
        for (int dx : {-1, 0, 1})
            for (int dy : {-1, 0, 1})
                for (int dz : {-1, 0, 1}){
                    int a = x + dx, b = y + dy, c = z + dz;
                    if (abs(a - x) + abs(b - y) + abs(c - z) == 1)
                        ans -= st.count({a, b, c});
                }
    }
    cout << ans << endl;
}

