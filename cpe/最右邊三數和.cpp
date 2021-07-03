#include<iostream>
using namespace std;
/*ex 1
   3 5 7 n=2 output 15
 9 11 13 15 17 n=3 output 45
*/
int main()
{
    int n;
    cin >> n;
    int an = (1+(2*n - 1))*n/2;//靠北2n-1為奇數拉幹
    int total = 1 + (an - 1) * 2 + 1 + (an-2)*2 + 1 + (an - 3) * 2;
    cout << an<<" "<<total;
}