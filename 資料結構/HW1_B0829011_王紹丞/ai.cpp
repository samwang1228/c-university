#include<iostream>
//#include<stdio.h>
#include<cstring>
#include<malloc.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    string s[x];
    cin.ignore();
    int max_size = 0;
    for (int i = 0; i < x;i++)
    {
        getline(cin, s[i]);
    }
    for (int i = 0; i < x;i++)
    {
        if(s[i].size()>max_size)
            max_size = s[i].size();
    }
    char **word;
    word = new char*[x];
    for (int i = 0; i < x;i++)
        word[i] = new char[max_size];
    for (int i = 0; i < x;i++)
    {
        for (int j = 0; j < s[i].size();j++)
            word[i][j] = s[i][j];
    }
    for (int i = 0; i < x;i++)
    {
        for (int j = 0; j < s[i].size();j++)
            cout<<word[i][j];
        cout << endl;
    }
}