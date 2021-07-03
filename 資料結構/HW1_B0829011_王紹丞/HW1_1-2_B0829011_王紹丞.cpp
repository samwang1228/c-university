#include<iostream>
//#include<stdio.h>
#include<cstring>
#include<malloc.h>
using namespace std;
void swapv(char *&a,char *&b)
{
    char *temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x,y;//x為字串數量 y為字串長度
    string s;
    cin >> x >> y;
    //char **p;
    // p = new char*[x];
    // for (int i = 0; i < x;i++)
    //     p[i] = new char[y];
    char **p = (char **)malloc(x * sizeof(char *));//malloc
    for (int i = 0; i < x;i++)
        p[i] = (char *)malloc(y * sizeof(char));
    getline(cin, s);//為了不要讀到換行
        for (int i = 0; i < x; i++)
        {
            while (getline(cin,s))//考慮Input不符合的情況
            {
                if (s.size() > y)
                cout << "Please input again" << endl;
                else if (s.size() < y)//在後面加空白
                {
                    for (int i = 0; i < y; i++)
                    {
                        s += " ";
                        if (s.size() == y)
                            break;
                        //goto start;
                    }
                }
                if (s.size()==y)
                    break;
            }
        //start:
        for (int j = 0; j < y; j++)//符合的字串則存取
        {
            p[i][j] = s[j];
        }
    }
    for (int i = 0; i < x-1; i++)//執行bubble sort
    {
        for (int j = 0; j < x -1-i;j++)
        {
            if(p[j][0]<p[j+1][0])
            {
                swapv(p[j], p[j + 1]);
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << p[i][j];
        }
        cout << endl;
    }
    // for (int i = 0; i < x;i++)
    //     delete [] p[i];
    // delete[] p;

    for (int i = 0; i < x;i++) // release memory of malloc
        free(p[i]);
    free(p);
}
