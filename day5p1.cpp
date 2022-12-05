#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    string s;
    int ans = 0;
    vector<string> st = {
        "JHGMZNTF",
        "JWV",
        "GVLJBTH",
        "BPJNCDVL",
        "FWSMPRG",
        "GHCFBNVM",
        "DHGMR",
        "HNMVZD",
        "GNFH"};
    for (int i = 0; i < 10; i++) getline(ifs, s);
    int a, b, c;
    while(getline(ifs, s)){
        for (int i = 0, j = 0; i < 6; i++, j++){
            string cur;
            while(s[j] != ' ') cur.push_back(s[j]), j++;
            if (i == 1) a = stoi(cur);
            if (i == 3) b = stoi(cur) - 1;
            if (i == 5) c = stoi(cur) - 1;
        }
        for (int i = 0; i < a; i++){
            if (st[b].empty()) break;
            st[c].push_back(st[b].back());
            st[b].pop_back();
        }
    }
    for (int i = 0; i < 9; i++){
        cout << st[i].back();
    }
}
                

