#include<iostream>
using namespace std;
int main(){
	int j,r,counter=0;
	int ansbox[512]={0};
	while(cin>>j>>r &&r &&j)
	{
		int player[512]={0};
		for(int i=0;i<r;i++)
		{
			for(int k=0;k<j;k++)
			{
				int temp;
				cin>>temp;
				player[k]+=temp;
			}
		}
		int max=player[0];
		int ans=0;
		for(int i=1;i<j;i++)
		{
//			cout<<i<<": "<<player[i]<<" end";
			if(player[i]>=max)
			{
				max=player[i];
				ans=i;
			}
		}
		ansbox[counter]=ans+1;
		counter++;
		
	}
	for(int i=0;i<counter;i++)
	{
		cout<<ansbox[i]<<endl;
	} 
}
