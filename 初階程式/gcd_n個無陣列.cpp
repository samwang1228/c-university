#include<iostream>
using namespace std;
int gcd(int x,int y){
 if(y==0)
    return x;
 else

	return gcd(y,x%y);

}
/*int gcd(int x,int y)
{
 while(x%y!=0)
 {
     int t = x%y;
     x = y;
     y = t;
 }
 return y;
}*/
int main()
{
    int n, v,a;
    cin >> n >> a;
    for (int i = 0; i < n-1;i++)
    {
        cin >> v;
        a = gcd(a, v);
    }
    cout << a;
}