#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    int s = 0;
    while(ifs.peek() != EOF){
        string a;
        getline(ifs, a);
        int x = a[0] - 'A', y = a[2] - 'X';
        s += y * 3;
        s += (x + y - 1 + 3) % 3 + 1;
        cout << s << endl;
    }
    cout << s << '\n';

}
