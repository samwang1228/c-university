#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;
int reverse(int x)
{
    int rev = 0;
    int pop;
    while(x!=0)
    {
        pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;
    }
    return rev;
    /*vector<int> p;
   int temp;爛方法
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
    return temp;*/
}
int main()
{
    long long int x;
    cin>>x;
    cout << reverse(x);
    //cout << INT_MIN << " " << INT_MAX;
}