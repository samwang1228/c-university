#include<iostream>
using namespace std;
int factor_table[1000];
void findFac(){
//	memset(factor_table, -1, sizeof(factor_table));
	int index=0;
	for(int i=0;i<=1000;i++)
		factor_table[i]=-1;
	for(int i=1;i<=1000;i++)
	{
		index=0;
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				index+=j;	
			}
		}
		if(index<=1000)
			factor_table[index]=i;
	} 
}
int main()
{
	int N,counter=0;
	findFac();
	while(cin>>N &&N)
	{
		cout<<"Case "<<++counter<<": "<<factor_table[N]<<endl;
	}
}
