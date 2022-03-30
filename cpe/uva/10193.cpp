#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;
long gcd(long a,long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	int N;
	cin>>N;
	string s1,s2;
	int Case=1;
	while(N--)
	{
		cin>>s1>>s2;
		long n1=0,n2=0; 
		for(int i=0;i<s1.size();i++)
		{
			n1=n1*2+s1[i]-'0';	
		}
		for(int i=0;i<s2.size();i++)
		{
			n2=n2*2+s2[i]-'0';	
		}
		if(gcd(n1,n2)!=1)
			cout<<"Pair #"<<Case++<<": All you need is love!";
		else
			cout<<"Pair #"<<Case++<<": Love is not all you need!";
		cout<<endl;
	}
} 
