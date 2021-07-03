#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int compare(int a[500],int b[500],int size)
{
    for (int i = size - 1; i >= 0;i--)
    {
        if(a[i]>b[i])
        {
            return 1;
            break;
        }
        else if(a[i]<b[i])
        {
            return -1;
            break;
        }
    }
    return 0;
}
void output(int c[500],int size)
{
    int i,j;
    bool n = 0;
    for ( i = size - 1; i >= 0;i--)
    {
        if (c[i] != 0)
        {
             n=true;
             j = i;
             break;
        }
    }
    if(n)
    {
        for ( int p=j; p >= 0;p--)
        {
            cout << c[p];
        }
    }  
    else
        cout << 0;
    cout << endl;
}
int main()
{
    char p;
    string s1,s2;
    while(cin >> s1 >> p >> s2)
    {
        int m = s1.size(),n=s2.size();
        int a[500] = {}, b[500] = {}, c[500] = {};
        int big = max(m, n);
        int carry=0;
        for (int i = 0; i < m;i++)
        {
            a[i] = s1[m-1-i] - '0';
        }
        for (int i = 0; i < n;i++)
        {
            b[i] = s2[n-1-i] - '0';
        }
        if(p=='+')
        {
            for (int i = 0; i < big;i++)
            {
                c[i] = a[i] + b[i]+carry;
                if(c[big-1]>=10)
                    break;
                if(c[i]>=10)
                {    
                    carry = 1;
                    c[i] %= 10;
                }
                else
                carry = 0;
            }
            output(c, big);
        }
        else if(p=='*')
        {
            for (int i = 0; i < m ; i++)
            {
                for (int j = 0; j < n;j++)
                {
                    c[i+j] += a[i] * b[j];
                }
            }
            for (int  k= 0;  k< m+n-1;  k++)//進位
            {
                c[k] += carry;
                carry = c[k] / 10;
                if(c[k]>=10&&k!=m+n-2)
                c[k] %= 10;
            }

            output(c, m + n - 1);
        }
        else if(p=='-')
        {
            int cheak=compare(a, b, big);
            if(cheak==1)
            {
            for (int i = 0; i < big  ; i++)
            {
                c[i] = a[i] - b[i] - carry;
                if(c[i]<0)
                {
                    c[i] += 10;
                    carry = 1;
                }
                else
                carry = 0;
            }
            output(c, big);
            }
            else if(cheak==0)
                cout << 0<<endl;
            else
            {
                 for (int i = 0; i < big  ; i++)
            {
                c[i] = b[i] - a[i] - carry;
                if(c[i]<0)
                {
                    c[i] += 10;
                    carry = 1;
                }
                else
                carry = 0;
            }
            cout << "-";
            output(c, big);
            }
        }
    }
}