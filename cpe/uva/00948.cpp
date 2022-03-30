#include<iostream>
using namespace std;
int main()
{
	int n;
	int fn[39]={0};
	fn[0]=1;
	fn[1]=2;
	for(int i=2;i<39;i++)
		fn[i]=fn[i-1]+fn[i-2];
	cin>>n;
	int num1;
	
	while(n--)
	{
		cin>>num1;
		cout<<num1<<" = ";
		bool flag=false;
		for(int i=38;i>=0;i--)
		{
			if(num1-fn[i]>=0)
			{
				cout<<1;
				num1-=fn[i];
				flag=true;
			}
			else if(flag)//找到第一個1才可以輸出0 
			{
				cout<<0;
			}
		}
		cout<<" (fib)"<<endl;
	}
}
