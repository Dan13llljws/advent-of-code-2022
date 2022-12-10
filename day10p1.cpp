#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    int a = 1, b = 1, ans = 0;
    while(getline(ifs, s)){
        if (s[0] == 'n'){
            b++;
            if (b % 40 == 20){
                ans += a * b;
            }
        } else {
            b++;
            if (b % 40 == 20){
                ans += a * b;
            }
            b++, a += stoi(s.substr(5));
            if (b % 40 == 20){
                ans += a * b;
            }
        }
    }
    cout << ans << '\n';
}

