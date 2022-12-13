#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    auto split = [&](string& str){
        vector<string> ret;
        int cnt = 0; 
        string s = "";
        for (int i = 1; i < (int)str.size() - 1; i++){
            char c = str[i];
            if (c == '[') cnt++;
            if (c == ']') cnt--;
            if (c == ',' && !cnt) ret.push_back(s), s = "";
            else s.push_back(c);
        } 
        if (s.size()) ret.push_back(s);
        return ret;
    };
    auto le = [&](auto self, string a, string b){
        int fa = a[0] == '[', fb = b[0] == '[';
        if (!fa && !fb){
            if (stoi(a) < stoi(b)) return 1;
            if (stoi(b) < stoi(a)) return -1;
            return 0;
        } else {
            if (!fa) a = "[" + a + "]";
            if (!fb) b = "[" + b + "]";
            vector<string> aa = split(a), bb = split(b);
            for (int i = 0; i < (int)min(aa.size(), bb.size()); i++){
                int ret = self(self, aa[i], bb[i]);
                if (ret) return ret;
            }
            if (aa.size() < bb.size()) return 1;
            if (aa.size() > bb.size()) return -1;
            return 0;
        }
    };
    vector<string> pack;
    while(getline(ifs, s)){
        if (s.size()) pack.push_back(s);
    }
    pack.push_back("[[2]]");
    pack.push_back("[[6]]");
    sort(pack.begin(), pack.end(), [&](string a, string b){
        return le(le, a, b) > 0;
    });
    int i = find(pack.begin(), pack.end(), "[[2]]") - pack.begin() + 1;
    int j = find(pack.begin(), pack.end(), "[[6]]") - pack.begin() + 1;
    cout << i * j << endl;
}
