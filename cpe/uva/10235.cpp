#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(long long n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
long long reverse(long long n) 
{
	long long re=0;
	while(n>0)
	{
		re=re*10+n%10;
		n/=10;
	}
	return re;
}
int main()
{
	long long num;
	while(cin>>num)
	{
		if(!isPrime(num))
		{
			cout<<num<<" is not prime."<<endl;	
		} 
		else
		{
			if(isPrime(reverse(num))&&reverse(num)!=num)
				cout<<num<<" is emirp."<<endl;
			else
				cout<<num<<" is prime."<<endl;
		}
	}
} 
