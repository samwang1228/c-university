#include<iostream>
using namespace std;
int gcd(int a,int b)
{
  while(a%b!=0)
  {
      int temp = a % b;
      a = b;
      b = temp;
  }
  return b;
}
int gcd2(int a, int b)
{
if (b == 0)
    return a;
else
    return gcd2(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}