#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    int sum = 0, ans = 0;
    while(ifs.peek() != EOF){
        string s;
        getline(ifs, s);
        if (s.empty()){
            sum = 0;
        } else {
            sum += stoi(s);
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

