#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
    int size, times = 0, max = 0,pos=0;
    cin >> size;
    string temp[size+1 ];
    //getline(cin, temp[times]);
    while(times<=size)
    {
        getline(cin, temp[times]);
        times++;
    }
    for (int i = 0; i <= size;i++)
    {
        if(temp[i].length()>max)
        {
            max = temp[i].length();
        }
    }
    char **p,**set;
    p = new char *[size];
    set = new char *[size];
    for (int i = 0; i < size;i++)
    {
        p[i] = new char[max];
        set[i] = new char[max];
    }
    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < max;j++)
        {
            p[i][j] = temp[i][j];
        }
    }
       for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < max;j++)
        {
            cout << p[i][j];
        }
        cout << endl;
    }
    // for (int i = 0; i < size;i++)
    // {
    //     for (int j = 0; j < max;j++)
    //     {
    //        if(p[i][j]==' ')
    //         {
    //             if(j>pos)
    //             {
    //                 pos = j;                    
    //             }
    //             break;
    //         }
    //     }
    // }
 
    // int x,y;
    // for (int i = 0; i < size;i++)
    // {
    //     x = 0;
    //     y = 0;
    //     for(int j = 0; j < max;j++)
    //     {
    //         x++;
    //         if(p[i][j]==' ')
    //         {
    //             for (int k = 0; k < pos - x;k++)
    //             {
    //                 set[i][k] = ' ';
    //             }
    //             for (int l = pos - x; l < max;l++)
    //             {
    //                 set[i][l] = p[i][y];
    //                 y++;
    //             }
    //             break;
    //         }
    //     }
    // }
    // for (int i = 0; i < size;i++)
    // {
    //     delete[] p[i];
    // }
    // delete[] p;
    // for (int i = 0; i < size;i++)
    // {
    //     for (int j = 0; j < max;j++)
    //     {
    //         cout << set[i][j];
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < size;i++)
    // {
    //     delete[] set[i];
    // }
    // delete[] set;
}
