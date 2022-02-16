#include<iostream>
#include<string>
using namespace std;
long long gcd(long long a, unsigned long long b) {
   long long t;
   while( b!=0 )
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}
int main()
{
	//hint 題目range 10^9 --> 2^30
	//t1*v2 ==2^60 超過int 2^31 
	//10^3 --> 2^10
	// long -->2^64
	long long v1,d1,v2,d2,counter=0;
	long long t1,t2;
	bool mode;
	string s1=" You owe me a beer!";
	string s2=" No beer for the captain.";
	double avg;
	while(cin>>v1>>d1>>v2>>d2 && v1 && d1 && v2 && d2)
	{
		t1=d1*v2;
		t2=d2*v1;
		long long a= t1+t2;//分子 
		long long b= v1*v2*2; //分母 
		if(t2>=t1)
			cout<<"Case #"<<counter+1<<":"<<s1<<endl;
		else 
			cout<<"Case #"<<counter+1<<":"<<s2<<endl;
		long long  g=gcd(a,b);
		a/=g;
		b/=g;	
		if(b==1)
			cout<<"Avg."<<" arrive time: "<<a<<endl;
		else
			cout<<"Avg."<<" arrive time: "<<a<<"/"<<b<<endl;
		counter++;
	}
}
