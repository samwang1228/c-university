#include<iostream>
#include<cmath>
#include<cstdlib> 
using namespace std;
class primeNumber
{
    public:
    primeNumber();
    primeNumber(int n);
    bool setprime(int n);
    bool setprime2();
    int getprime();
    primeNumber operator+(primeNumber p2);
    primeNumber operator-(primeNumber p2);
    primeNumber operator+(int n);
private:
    int prime;
};
primeNumber primeNumber::operator+(primeNumber p2)
{
    primeNumber p3(prime + p2.getprime());
    return p3;
}
primeNumber primeNumber::operator-(primeNumber p2)
{
    return  primeNumber (abs(prime - p2.getprime()));
}
primeNumber primeNumber::operator+(int n)
{
    int t = 0;
    int ans;
    for (int i = prime; ; i++)
    {
        bool test = true;
        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                test = false;
                break;
            }
        }
        if(test)
        {
            ++t;
        }
        if(t>n)
        {
             ans = i;
            break;
        }
    }
    return primeNumber(ans);
}
primeNumber::primeNumber()
{
    prime = 0;
}
primeNumber::primeNumber(int n)
{
    prime = n;
}
bool primeNumber::setprime(int n)
{
    for (int i = n; i >= n;i++)
    {
        bool test = true;
        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                test = false;
                break;
            }
        }
        if(test)
        {
            prime = i;
            return true;
        }
    }
    return false;
}
bool primeNumber::setprime2()
{
    for (int i = prime; i >= prime;i++)
    {
        bool test = true;
        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                test = false;
                break;
            }
        }
        if(test)
        {
            prime = i;
            return true;
        }
    }
    return false;
}
int primeNumber::getprime()
{
    return prime;
}
int main()
{
    primeNumber p1, p2,p3;
    int s, type,number,a,b;
    cin >> s  ;
    srand(s);
    while(cin>>type>>a>>b)
    {
        if(type==3)
            break;
    if(type==0)
    {
        if(a==0)
        {
        p1 = primeNumber();
        number = rand() % 9001 + 1000;
        p1.setprime(number);
        }
        if(b==0)
        {
        p2 = primeNumber();
        number = rand() % 9001 + 1000;
        p2.setprime(number);
        }
        if(a!=0)
        {
            p1 = primeNumber(a);
            p1.setprime(a);
        }
        if(b!=0)
        {
            p2=primeNumber(b);
            p2.setprime(b);
        }
        p3 = p1 + p2;
        p3.setprime2();
        cout<<p3.getprime()<<endl;
    }
    if(type==1)
    {
        if(a==0)
        {
        p1 = primeNumber();
        number = rand() % 9001 + 1000;
        p1.setprime(number);
        }
        if(b==0)
        {
        p2 = primeNumber();
        number = rand() % 9001 + 1000;
        p2.setprime(number);
        }
        if(a!=0)
        {
            p1 = primeNumber(a);
            p1.setprime(a);
        }
        if(b!=0)
        {
            p2=primeNumber(b);
            p2.setprime(b);
        }
        p3 = p1 - p2;
        p3.setprime2();
        cout<<p3.getprime()<<endl;
    }
    if(type==2)
    {
        if(a==0)
        {
        p1 = primeNumber();
        number = rand() % 9001 + 1000;
        p1.setprime(number);
        }
        if(a!=0)
        {
            p1 = primeNumber(a);
            p1.setprime(a);
        }
        p3 = p1 + b;
        cout<<p3.getprime()<<endl;
    }
    }
}
