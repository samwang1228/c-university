#include<iostream>
using namespace std;
int hanoitotal=0;
int add(int n);//1加到n
int gcd(int a, int b);//最大公因數 
int binarySearch(int arr[], int L, int H, int x);//二元搜尋法 T(n/2^k)+kc (1+log2n)c以二為底 1=2^k k=log2n
int powernumber(int power, int radix);//樹狀
void hanoi(int n, char a, char c, char b);//把n個盤子從a移到c並用b做緩衝
int bulb(int bulbnumber, int bulbtype);//若前面燈泡亮則後面燈泡只能不亮 反之皆可 算出總數目
int power(int a, int n);//a^n
int level(int n);//n!
int main()
{
    /*int x;
    int a, b;
    cout<<"input one variable we will from 1 add to x"<<endl;
    cin>>x;
    cout<<add(x)<<endl;
    cout<<"two variables we will get gcd"<<endl;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    int ballnumber, balltype;
    cin >> ballnumber >> balltype;
    cout << powernumber(ballnumber, balltype) << endl;*/
    //int *p, h, l=0, test;
   /* cout << "input the array size and you want to check number in this array"<<endl;
    cin >> h >> test;
    p = new int[h];
    for (int i = 0; i < h;i++)
        p[i] = i+1;
    cout << binarySearch(p, l, h, test);*/
    int n;
    cout << "input ring number we will get step by step and total move"<<endl;
    cin >> n;
    hanoi(n, 'a', 'c', 'b');
    cout << hanoitotal << endl;
    cout << "input bulb number" << endl;
    cin >> n;
    cout << bulb(n, 0);
    cout << level(n);
}
int add(int n)
{
    if(n>0)
    {
        return n+add(n-1);
    }
    return 0;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int powernumber(int power,int radix)
{
    if(power>0)
    {
        int total = 0;
        for (int i = 0; i < radix;i++)//算有幾個要分支ex if balltype=3 那就有三種球每種球都要三個分支
        {
            total += powernumber(power - 1, radix);//power為層數 radix為分支
        }
        return total;
    }
    return 1;//0次方皆為1
}
int binarySearch(int arr[], int L, int H, int x)
{
    if ( H < L )
        return -1;
    else
    {
        int mid = L + ( H - L ) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr,L,H=mid-1,x);
        return  binarySearch(arr,L=mid+1,H,x);
    }
}
void hanoi(int n, char a, char c, char b)//1 3 2
{
    if(n==1)
    {
        cout << "ring 1 from " << a << " to " << c << endl;
        hanoitotal++;
    }
    else//用兩個圓盤想
    {
        hanoi(n - 1, a, b, c);//N - 1 層的圓盤先移到 B 桿 最上為1
        cout << "ring " << n << " from " << a << " to " << c << endl;
        hanoitotal++;              //N 層的圓盤移到 C 桿
        hanoi(n - 1, b, c, a);//B 桿上的圓盤全部移到 C
    }
}
int bulb(int bulbnumber, int bulbtype) 
{
    if(bulbnumber>0&&bulbtype==0)
        return bulb(bulbnumber - 1, 0) + bulb(bulbnumber - 1, 1);
    else if(bulbnumber>0&&bulbtype==1)
        return bulb(bulbnumber - 1, 0);
    else
        return 1;
}
int power(int a, int n)
{
    if(n>0)
        return a * power(a, n - 1);
    return 1;
}
int level(int n)
{
    if(n==1)
        return 1;
    return n * level(n - 1);
}

