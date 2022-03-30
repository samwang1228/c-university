#include<iostream>
using namespace std;
void divide(long long &N)
{
	int temp=0;
//	long long n=N;
	while(N>0)
	{
		temp+=N%10;
		N/=10;
	}
	N=temp;
}
int main()
{
	long long N;
	while(cin>>N)
	{
		if(N==0)
			break;
		while(N>=10)
		{
		divide(N);
		}
		cout<<N<<endl;
	} 
}
  
