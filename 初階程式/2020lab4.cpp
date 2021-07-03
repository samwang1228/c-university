#include<fstream>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    ifstream instream;
    ofstream outstream;
    instream.open("1.in.txt");
    outstream.open("1.out.txt");
    int s0;//題目是把第一個字元當作數字所以要用int存
    char s;
    int n = 0;
    while(instream.get(s))
    {
        if(n==0)
    {
        s0=s;
        n++;
        outstream.put(s);
    }
    else{
    int ans = s ^ s0;
    char ans2 = ans;
    outstream.put(ans2);//要轉成char才能使用put
    }
    }
}