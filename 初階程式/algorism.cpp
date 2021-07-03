#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    char p[s.size()];
    for (int i = 0; i < s.size();i++)
    {
        p[i] = s[i];
    }
    sort(p, p + s.size());
    cout << p << endl;
    sort(p + s.size(),p+ 0);
    cout << p;
}