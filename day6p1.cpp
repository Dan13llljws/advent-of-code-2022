#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("in");
    string s;
    getline(ifs, s);
    for (int i = 0; i < (int)s.size(); i++){
        set<char> st;
        for (int j = i; j < min((int)s.size(), i + 14); j++)
            st.insert(s[j]);
        if (st.size() == 14){
            cout << i + 14 << '\n';
            return 0;
        }
    }
}

