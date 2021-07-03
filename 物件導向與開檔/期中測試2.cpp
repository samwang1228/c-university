#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    string **p;
    srand(time(0));
    int x, y, length;
    cin >> x >> y >> length;
    p=new string *[x];
    for (int i = 0; i < x;i++)
    {
        p[i] = new string[y];
    }
    int a, b;
        for (int i = 0; i < x;i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < length;k++)
                {
                    int omg=rand()%26;
                    p[i][j] += 'a'+omg;
                }
            }
        }
    while(cin>>a>>b)
    {
        if(a<0||b<0)
            break;
        cout << p[a][b]<<endl;
    }
    
}