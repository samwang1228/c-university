#include<iostream>
using namespace std;
int main()
{
	int num1,num2;
	int count=0;
	int o_carry=0;
	int n_carry=0;
	while(cin>>num1>>num2)
	{
		count=0;
		n_carry=0;
		if(num1==0&&num2==0)
			break;
		while(num1>0||num2>0)
		{	
			int m1,m2;
			m1=num1%10;
			m2=num2%10;
			if(m1+m2+n_carry>=10)
			{
				n_carry=1;
				count++;
			}
			else{
				n_carry=0;
			}
			if(num1>0)
			num1/=10;
			if(num2>0)
			num2/=10;
		}
		if(count>1)
			cout<<count<<" carry operations."<<endl;
		else if(count==1)
			cout<<"1 carry operation."<<endl;
		else
			cout<<"No carry operation."<<endl;
	}
}
