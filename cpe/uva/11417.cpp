#include<iostream> 
using  namespace std;
int GCD(int a,int b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}
int main()
{
	int N;
	while(cin>>N)
	{
		int temp=0;
		if(N==0)
			break;
		for(int i=1;i<N;i++)
		{
			for(int j=i+1;j<=N;j++)
			{
				temp+=GCD(i,j);
			}
		}
		cout<<temp<<endl;
	}
}
