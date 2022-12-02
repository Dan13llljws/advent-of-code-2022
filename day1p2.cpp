#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    vector<int> v;
    int sum = 0;
    while(ifs.peek() != EOF){
        string s;
        getline(ifs, s);
        if (s.empty()){
            v.push_back(sum);
            sum = 0;
        } else {
            sum += stoi(s);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[0] + v[1] + v[2] << endl;
}

