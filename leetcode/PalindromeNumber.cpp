#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int reverse(int x)
{
   vector<int> p;
   int temp;
    while(x!=0)
    {
        temp=x % 10;
        p.push_back(temp);
        x /= 10;
    }
    int size = p.size();
    temp = 0;
    for (int i = 0; i < p.size(); i++)
    {
        temp += p[i]*pow(10,size-1);
        --size;
    }
    return temp;
}
int main()
{
    long long int x;
    cin >> x;
    if(x<0)
    {
        cout << "false";
    }
    else 
    {
        if(reverse(x)==x)
            cout << "true";
        else
            cout << "false";
    }
}