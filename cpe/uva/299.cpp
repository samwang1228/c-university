#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int size;
	while(N--)
	{
		cin>>size;
		int ans[size]={};
		int count=0;
		for(int i=0;i<size;i++)
		{
			cin>>ans[i];
		}
		for(int i=0;i<size-1;i++)
		{
			for(int j=0;j<size-1-i;j++)
			{
				if(ans[j]>ans[j+1])
				{
					count++;
					int temp=ans[j];
					ans[j]=ans[j+1];
					ans[j+1]=temp;	
				}	
			}	
		}
		cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;	
	}	
} 
