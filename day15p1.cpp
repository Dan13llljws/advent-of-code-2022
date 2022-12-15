#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("in");
    string s, t;
    set<int> st, bc;
    while(ifs >> s >> s >> s >> t){
        s.pop_back(), t.pop_back();
        int x = stoi(s.substr(2));
        int y = stoi(t.substr(2));
        ifs >> s >> s >> s >> s >> s >> t;
        s.pop_back();
        int a = stoi(s.substr(2));
        int b = stoi(t.substr(2));
        if (b == 2e6) bc.insert(a);
        int d = abs(x - a) + abs(y - b);
        d -= abs(2e6 - y);
        if (d > 0){
            for (int i = x - d; i <= x + d; i++)
                st.insert(i);
        }
    }
    for (int x : bc) st.erase(x);
    cout << st.size() << endl;
}


