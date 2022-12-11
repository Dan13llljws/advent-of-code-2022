#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    string gar;
    vector<vector<ll>> item;
    vector<ll> op, op2, t1, t2, t3;
    while(ifs >> gar >> gar){
        ifs >> gar >> gar;
        string lst;
        getline(ifs, lst);
        item.push_back(vector<ll>());
        int x = 0;
        for (auto c : lst){
            if (isdigit(c)){
                x = x * 10 + c - '0';
            } else {
                if (x) item.back().push_back(x);
                x = 0;
            }
        } item.back().push_back(x);
        for (int i = 0; i < 5; i++)
            ifs >> gar;
        if (gar == "*"){
            ifs >> gar;
            op.push_back(0);
            if (gar == "old")
                op2.push_back(-1);
            else 
                op2.push_back(stoi(gar));
        } else {
            ifs >> gar;
            op.push_back(1);
            if (gar == "old")
                op2.push_back(-1);
            else 
                op2.push_back(stoi(gar));
        }
        for (int i = 0; i < 4; i++)
            ifs >> gar;
        t1.push_back(stoi(gar));
        for (int i = 0; i < 6; i++)
            ifs >> gar;
        t2.push_back(stoi(gar));
        for (int i = 0; i < 6; i++)
            ifs >> gar;
        t3.push_back(stoi(gar));
    }
    int n = op.size();
    vector<ll> sz(n);
    for (int round = 0; round < 20; round++){
        for (int i = 0; i < n; i++){
            sz[i] += item[i].size();
            for (ll x : item[i]){
                ll w = 0;
                if (!op[i]){
                    if (op2[i] == -1) 
                        w = x * x;
                    else 
                        w = x * op2[i];
                } else {
                    w = (x + op2[i]);
                } w /= 3;
                if (w % t1[i] == 0)
                    item[t2[i]].push_back(w);
                else 
                    item[t3[i]].push_back(w);
            }
            item[i].clear();
        }
    }
    sort(sz.begin(), sz.end(), greater<ll>());
    cout << sz[0] * sz[1] << endl;
}
