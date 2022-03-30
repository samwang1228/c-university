#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int size;
	while(N--)
	{
		cin>>size;
		int mid=size/2;
		int temp[size]={0};
		int sum=0;
		for(int i=0;i<size;i++)
		{
			cin>>temp[i];
		}
		sort(temp,temp+size);
		for(int i=0;i<size;i++)
		{
			sum+=abs(temp[i]-temp[mid]);
		} 
		cout<<sum<<endl;
	}
}
