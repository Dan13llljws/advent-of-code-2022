#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    string s;
    int ans = 0;
    while(getline(ifs, s)){
        vector<int> a;
        int x = 0;
        for (char c : s){
            if (isdigit(c)){
                x = x * 10 + c - '0';
            } else {
                a.push_back(x);
                x = 0;
            }
        }
        a.push_back(x);
        if (a[0] <= a[2] && a[1] >= a[3]) ans++;
        else if (a[0] >= a[2] && a[1] <= a[3]) ans++;
    }
    cout << ans << '\n';
}
