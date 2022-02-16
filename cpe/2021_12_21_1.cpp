#include<iostream>
using namespace std;
int main(){
	int N,size;
	cin>>N;
	int counter=0;
	int ans[N]={0};
	for(int i=0;i<N;i++)
	{
		cin>>size;
		int a[size]={0};
		cin>>a[0];
		for(int j=1;j<size;j++)
		{
			cin>>a[j];
			for(int k=0;k<j;k++)
			{
				if(a[k]<=a[j])
					ans[counter]++;
			}
		}
		counter++;
//		cout<<ans[0]<<endl;
	}
	for(int i=0;i<N;i++)
	cout<<ans[i]<<endl;
} 
