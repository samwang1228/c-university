#include<iostream>
using namespace std;
int main()
{
	int num1,num2,count=0,max=0,s,l;
//	int n=11;
//	cout<<(n&1);
	while(cin>>num1>>num2)
	{
		max=0;
		if(num2<num1)
		{
			s=num2;
			l=num1;
		}
		else
		{
			s=num1;
			l=num2; 
		}
		for(int i=s;i<=l;i++)
		{
			int k=i;//«Ü­«­n
			count=1; 
			bool isOne=true;
			while(k!=1)
			{
				if(isOne)
					isOne=false;
				if(k%2)
				{
					k=3*k+1; 
				}
				else
				{
					k/=2;
				}
				++count;
				if(count>max)
				max=count;
			}
			if(isOne)
				max=1;
//			cout<<i<<endl;
		}
		cout<<num1<<" "<<num2<<" "<<max<<endl;
	}
}
