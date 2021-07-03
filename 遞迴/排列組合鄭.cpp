#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include<time.h>
using namespace std;
char *p;
string s;
void sortword(int k)
{
    if (k == s.size())
    {
        for (int j = 0  ; j < s.size(); j++)
        {
            cout << p[j];
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = k; i < s.size(); i++) //第i个数分别與它後面的數字交换就能得到新的排列
        {
//            cout << "i=" << i << " k=" << k << " "; //第一次i=0,k=0,i=1,k=1;i=2,k=2
            swap(p[i], p[k]); //len=3，分别得到abc,bac,cba
            sort(p + 1 + k, p + s.size()); //對除了第一个數排序，如abc，對bc排序
            sortword(k + 1); //遞迴
            //i=2(上次的)之後++爆掉 下次i=1 k再返回=1
            sort(p + k, p + s.size());//順序改回來
        }
    }
}
int main()
{
    cin >> s;
    p = new char[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        p[i] = s[i];
    }
    sort(p, p + s.size());
    sortword(0);
    return 0;
}
