#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string s;
    int a = 1, b = 1, ans = 0;
    vector<vector<char>> g(10, vector<char>(40, '.'));
    auto draw = [&](){
        g[b / 40][b % 40] = (abs(a - ((b - 1) % 40)) <= 1 ? '#' : '.');
    };
    while(getline(ifs, s)){
        if (s[0] == 'n'){
            b++;
            if (b % 40 == 20){
                ans += a * b;
            }
            draw();
        } else {
            b++;
            if (b % 40 == 20){
                ans += a * b;
            }
            draw();
            b++, a += stoi(s.substr(5));
            if (b % 40 == 20){
                ans += a * b;
            }
            draw();
        }
    }
    for (auto v : g){
        for (auto c : v) cout << c;
        cout << endl;
    }
}

