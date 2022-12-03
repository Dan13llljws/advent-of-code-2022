#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    string s;
    int sum = 0;
    while(getline(ifs, s)){
        int n = s.size() / 2;
        string a = s.substr(0, n), b = s.substr(n, n + n);
        set<char> s1, s2;
        for (char c : a)
            s1.insert(c);
        for (char c : b)
            s2.insert(c);
        char x = 0;
        for (char c : b)
            if (s1.count(c))
                x = c;
        if (x >= 'A' && x <= 'Z') sum += 27 + x - 'A';
        else sum += 1 + x - 'a';
        cout << x <<endl;
    }
    cout << sum  << endl;
}
