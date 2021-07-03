#include<iostream>//uva10101
#include<climits>
#include<cstring>
using namespace std;
int main()
{
    string s;
    int con = 1;
    //int sh = 100,ha=1000,la=100000,ku=1000000;
    while(cin >> s)
    {
        cout << con << ". ";
        con++;
        int ans[8];
        int last = s[s.size() - 1]-'0' + (s[s.size() - 2]-'0') * 10;
        int t = 0;
        int n = 3;
        int size = s.size();
        if (size > 10)
            size++;
        if (size >= 3)
        {
            for (int i = s.size() - 3; i >= 0; i--)
            {
                if (size % 2 == 1)
                {
                    if (n == 10 && i != 0)
                    {
                        n = 3;
                    }
                    if (n == 3)
                    {
                        ans[t] = s[i] - '0';
                        t++;
                    }
                    else if (i == 0)
                    {
                        ans[t] = (s[i] - '0') * 10 + s[i + 1] - '0';
                    }
                    else if (n > 3 && n % 2 != 0)
                    {
                        ans[t] = (s[i] - '0') * 10 + s[i + 1] - '0';
                        t++;
                    }
                    ++n;
                }
                else
                {
                    if (n == 10 && i != 0)
                    {
                        n = 3;
                    }
                    if (n == 3)
                    {
                        ans[t] = s[i] - '0';
                        t++;
                    }
                    else if (i == 0)
                    {
                        ans[t] = s[i] - '0';
                    }
                    else if (n > 3 && n % 2 != 0)
                    {
                        ans[t] = (s[i] - '0') * 10 + s[i + 1] - '0';
                        t++;
                    }
                    ++n;
                }
            }
            //int n = t;
            for (int i = t; i >= 0; i--)
            {
                if (i == 7)
                {
                    if(ans[i]!=0)
                    cout << ans[i] << " kuti ";
                }
                if ( i == 3)
                {
                    if(ans[i]!=0)
                    cout << ans[i] << " kuti ";
                    else 
                    cout  << "kuti ";
                }
                if (i == 6 )
                {
                    if(ans[i]!=0)
                    cout << ans[i] << " lakh ";
                }
                if ( i == 2)
                {
                    if(ans[i]!=0)
                    cout << ans[i] << " lakh ";
                    else 
                     cout  << "lakh ";
                }
                if ( i == 1)
                {
                    if(ans[i]!=0)
                        cout << ans[i] << " hajar ";
                    else 
                    cout << "hajar ";

                }
                if (i == 5 )
                {
                    if(ans[i]!=0)
                        cout << ans[i] << " hajar ";

                }
                if (i == 4 )
                {
                   if(ans[i]!=0)
                    cout << ans[i] << " shata ";
                }
                if ( i == 0)
                {
                   if(ans[i]!=0)
                    cout << ans[i] << " shata ";
                    else 
                    cout  << "shata ";
                }
            }
    }
    if(last!=0)
        cout << last << endl;
    }
    return 0;
}