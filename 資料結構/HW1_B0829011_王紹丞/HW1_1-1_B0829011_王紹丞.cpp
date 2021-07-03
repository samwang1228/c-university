#include<iostream>
//#include<stdio.h>
#include<cstring>
#include<malloc.h>
using namespace std;
int main()
{
    int x,y;
    string s;
    cout << "Number of string"<<endl;
    cin >> x ;
    cout << "Size of string"<<endl;
    cin >> y;
    char **p;
    p = new char*[x];
    for (int i = 0; i < x;i++)
        p[i] = new char[y];
    // char **p = (char **)malloc(x * sizeof(char *));//malloc
    // for (int i = 0; i < x;i++)
        // p[i] = (char *)malloc(y * sizeof(char));
    getline(cin, s);
    for (int i = 0; i < x; i++)
    {
        while (getline(cin, s))
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
            if (s.size() == y)
                break;
        }
        //start:
        for (int j = 0; j < y; j++)
        {
            p[i][j] = s[j];
        }
    }
    for (int i = 0; i < x;i++)
    {
        for (int j = 0; j < y; j++)
            cout << p[i][j];
        cout << endl;
    }
    for (int i = 0; i < x;i++)
        delete [] p[i];
    delete[] p;

    // for (int i = 0; i < x;i++) // release memory of malloc
    //     free(p[i]);
    // free(p);
}
