#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("in");
    string s;
    getline(ifs, s);
    for (int i = 0; i < (int)s.size(); i++){
        set<char> st;
        for (int j = i; j < min((int)s.size(), i + 4); j++)
            st.insert(s[j]);
        if (st.size() == 4){
            cout << i + 4 << '\n';
            return 0;
        }
    }
}

