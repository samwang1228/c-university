#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> x;
    for (int i = 0; i < 10;i++)
    {
        x.push_back(i);
    }
    // for (int i = 0; i < x.size();i++)
    // {
    //     cout << x[i];
    // }
    vector<int>::iterator begin = x.begin();
    vector<int>::iterator end = x.end();
    vector<int>::iterator it;
    for (it=begin; it !=end; it++)
    {
        cout << *it;
    }
}