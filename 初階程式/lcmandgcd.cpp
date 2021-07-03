#include<iostream>
using namespace std;
int gcd(int x,int y){
 if(y==0)
    return x;
 else

	return gcd(y,x%y);

}
int main()
{
    int x, y;
    cin >> x >> y;
    if(x<=0||y<=0)
    {
        cout << 0 << " " << 0 << endl;
    }
    else{
        cout << gcd(x, y) <<" ";
        int lcm;
        lcm = x * y /gcd(x,y) ;//兩數相乘除gcd等於lcm
        cout << lcm << endl;
    }
}