#include<iostream>
using namespace std;
int main() 
{
    int start, a, b, c;
    const int one_degree = 360 / 40;
    while(cin>>start>>a>>b>>c)
    {
        int total;
        if(start==0&&a==0&&b==0&c==0)
            break;
        total = 720 + (40 +start-a)%40 * one_degree+360+(40-a+b)%40*one_degree +(40 +b-c)%40 * one_degree;
        cout << total << endl;
    }
    return 0;
}