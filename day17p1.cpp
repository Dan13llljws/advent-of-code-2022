#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("in");
    string move;
    ifs >> move;
    vector<vector<pair<int,int>>> rock = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                                         {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1}},
                                         {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}},
                                         {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                                         {{0, 0}, {0, 1}, {1, 0}, {1, 1}}};
    int cnt = 0, rockid = 0, mxh = 0;
    vector<pair<int,int>> cur_rock;
    set<pair<int,int>> vis;
    auto new_rock = [&](){
        cur_rock = rock[rockid++];
        if (rockid == 5) rockid = 0;
        for (auto &x : cur_rock){
            x.first += mxh + 4, x.second += 2;
        }
    };
    auto check = [&](vector<pair<int,int>> r){
        for (auto p : r){
            if (vis.count(p)) return 0;
            if (p.second < 0 || p.second > 6 || p.first < 1) return 0;
        }
        return 1;
    };
    new_rock();
    while(1){
        for (char mv : move){
            int delta = (mv == '<' ? -1 : 1);
            vector<pair<int,int>> r = cur_rock;
            for (auto &p : r) p.second += delta;
            if (check(r)) cur_rock = r;
            r = cur_rock;
            for (auto &p : r) p.first--;
            if (check(r)) cur_rock = r;
            else {
                for (auto p : cur_rock)
                    mxh = max(mxh, p.first), vis.insert(p);
                new_rock(), cnt++;
                if (cnt == 2022){
                    cout << mxh << endl;
                    return 0;
                }
            }
        }
    }

            

        
}
