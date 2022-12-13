#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s, t;
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
    int idx = 0, ans = 0;
    while(cin >> s >> t){
        idx++;
        if (le(le, s, t) >= 0) ans += idx;
    }
    cout << ans << endl;
}
