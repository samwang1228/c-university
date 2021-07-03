#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
vector<int> p;
int n;
char c;
int temp;
while (cin >> n)
{
    while (scanf("%d%c",&temp,&c))
    {
        if(c!=' ')
            break;
        else
        p.push_back(temp);
    }
    temp = 0;
    //cout << "the size is "<<p.size()<<endl;
    for (int i = p.size() - 1,j=0; i >= 0;i--,j++)
    {
        temp += p[j] * (i+1) * pow(n, i );
    }
    cout << temp<<endl;
    p.clear();
}
}