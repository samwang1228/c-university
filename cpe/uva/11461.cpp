#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n1,n2,count=0;
	while(cin>>n1>>n2)
	{
		if(n1==0&&n2==0)
			break;	
		count=0;
		if(n1>n2)
		{
			int temp=n1;
			n1=n2;
			n2=temp;
		}
		for(int i=n1;i<=n2;i++)
		{
			int temp1=(int)sqrt(i);
			double temp2=sqrt(i);
			if(temp2-temp1==0)
				count++;
		}
		cout<<count<<endl;
	}	
} 
