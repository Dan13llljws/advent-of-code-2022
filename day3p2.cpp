#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    string s;
    int sum = 0;
    while(getline(ifs, s)){
        string a, b;
        getline(ifs, a);
        getline(ifs, b);
        set<char> s1, s2, s3;
        for (char c : a)
            s1.insert(c);
        for (char c : b)
            if (s1.count(c))
                s2.insert(c);
        char x = 0;
        for (char c : s)
            if (s2.count(c))
                x = c;
        if (x >= 'A' && x <= 'Z') sum += 27 + x - 'A';
        else sum += 1 + x - 'a';
        cout << x <<endl;
    }
    cout << sum  << endl;
}
