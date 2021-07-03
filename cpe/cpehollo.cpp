#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,i=1;
   while(true)
    {
        cin >> n;
        if(n<0||n>10001)
            break;
        else if(n==0)
       cout <<"Case "<< i << ": " <<0 << endl;
       else if(n>0)
       {
        float po = (log(n) / log(2));
        int power = (log(n) / log(2));
         if(po-power==0)
             power = po;
            else
                ++power;
        cout <<"Case "<< i << ": " << power << endl;
       }
        i++;
    }
}