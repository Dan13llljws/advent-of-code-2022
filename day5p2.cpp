#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    string s;
    int ans = 0;
    vector<string> st = {
        "JHGMZNTF",
        "VWJ",
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
        s +=  " ";
        for (int i = 0, j = 0; i < 6; i++, j++){
            string cur = "";
            while(s[j] != ' ') cur.push_back(s[j]), j++;
            if (i == 1) a = stoi(cur);
            if (i == 3) b = stoi(cur) - 1;
            if (i == 5) c = stoi(cur) - 1;
        }
        string tmp = "";
        for (int i = 0; i < a; i++){
            tmp.push_back(st[b].back());
            st[b].pop_back();
        }
        reverse(tmp.begin(), tmp.end());
        for (char ch : tmp)
            st[c].push_back(ch);
    }
    for (int i = 0; i < 9; i++){
        cout << st[i].back();
    }
}
                

