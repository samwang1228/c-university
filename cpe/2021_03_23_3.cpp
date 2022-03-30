#include<iostream>
//#include <cstdlib>
#include<iomanip> //for setw setfill
using namespace std;
bool isNoRepeat(int a,int b)
{
	if(a<10000&&b<10000)
		return false;
	bool n[10]={false};
	if(a<10000|| b<10000)
		n[0]=true;
	while(a>0)
	{
		if(n[a%10])
			return false;
		else
			n[a%10]=true;
		a/=10; 
	}
	while(b>0)
	{
		if(n[b%10])
			return false;
		else
			n[b%10]=true;
		b/=10; 
	}
	return true;
}
int main()
{
	int N;
	while(1)
	{
		cin>>N;
		int a;
		bool ans=false; 
		if(N==0)
			break;
		for(int i=1234;i<49876;i++)
		{
			a=i*N;
			if(isNoRepeat(a,i))
			{
				ans=true;
				cout<<setw(5)<<setfill('0')<<a;
				cout<<" / ";
				cout<<setw(5)<<setfill('0')<<i;
				cout<<" = "<<N<<endl;
			}	
		}
		
		if(!ans)
		{
			cout<<"There are no solutions for "<<N<<"."<<endl<<endl;
		}
		else
		{
			cout<<endl;
		}
	}
} 
