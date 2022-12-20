#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    vector<int> a, b, pos;
    int x, id = 0;
    while(ifs >> x){
        a.push_back(x);
        b.push_back(id);
        pos.push_back(id++);
    }
    for (int i = 0; i < id; i++){
        int f = a[pos[i]] > 0 ? 1 : -1;
        for (int j = 0; j < abs(a[pos[i]]); j++){
            int p = (pos[i] + f + id) % id;
            swap(a[pos[i]], a[p]);
            int tmp = b[p];
            swap(b[pos[i]], b[p]);
            swap(pos[i], pos[tmp]);
        }
    }
    int p = 0;
    for (int i = 0; i < id; i++)
        if (a[i] == 0) p = i;
    cout << a[(1000 + p) % id] + a[(2000 + p) % id] + a[(3000 + p) % id] << endl;
}
