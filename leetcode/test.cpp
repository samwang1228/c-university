#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int x=7,y;
    //char **p,t;
    // int temp_adress=99;
    // p = new char*[x];
    // for (int i = 0; i < x;i++)
    //     p[i] = new char[temp_adress];
    // cin.get(t);
    // for (int i = 0; i < x;i++)
    // {
    //     int j = 0;
    //     while (cin.get(t))
    //     {
    //         if(t=='\n')
    //             break;
    //         p[i][j] = t;
    //         ++j;
    //     }
    // }
    // for (int i = 0; i < x;i++)
    // {
    //     for (int j = 0; j < 20;j++)
    //         cout << p[i][j];
    //     cout << endl;
    // }
    bool test = true;
    while(cin>>y)
    {
        test = true;
        for (int i = 0; i < 3;i++)
        {
            cout << i<<" ";
            if (x == 7 && y == 9 && test)
            {
                cout << "fuck";
                test = false;
            }
        }
    }
}