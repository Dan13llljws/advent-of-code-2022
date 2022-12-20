#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ifstream ifs("in");
    vector<ll> a, b, pos;
    ll x, id = 0;
    const ll key = 811589153;
    while(ifs >> x){
        a.push_back(x * key);
        b.push_back(id);
        pos.push_back(id++);
    }
    for (int t = 0; t < 10; t++){
        for (int i = 0; i < id; i++){
            ll v = a[pos[i]] % (id - 1);
            int f = v > 0 ? 1 : -1;
            for (int j = 0; j < abs(v); j++){
                int p = (pos[i] + f + id) % id;
                swap(a[pos[i]], a[p]);
                int tmp = b[p];
                swap(b[pos[i]], b[p]);
                swap(pos[i], pos[tmp]);
            }
        }
    }
    int p = 0;
    for (int i = 0; i < id; i++)
        if (a[i] == 0) p = i;
    cout << a[(1000 + p) % id] + a[(2000 + p) % id] + a[(3000 + p) % id] << endl;
}
