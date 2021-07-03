#include<iostream>
using namespace std;
int main()
{
    int x, h, m, s;
    cin >> x;
    h = x / 3600;
    m = (x - h * 3600) / 60;
    s = x - h * 3600 - m * 60;
    if(x%3600<12)
    {
        if(m<10)
        {
            cout << " AM " << h << ':' << "0" << m << ':' << s;
        }
        if(m>=10)
        {
            cout << " AM " << h << ':' << m <<':'<< s;
        }
    }
    if(x%3600>12)
    {
        if(m<10)
        {
            cout << " PM " << h%12 << ':' << "0" << m << ':' << s;
        }
        if(m>=10)
        {
            cout << " PM " << h%12 << ':' << m <<':'<< s;
        }
    }
    return 0;
}