#include<iostream>
#include<set>
using namespace std;
int main()
{
	
	int n,counter=1;
	while(cin>>n)
	{
		int num[n]={0};
		set<int> map;
		map.clear();
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<n;i++)
		{
			
			if(num[i]<1)
			{
				break;	
			}	
			else if(num[i-1]>num[i]&&i-1>0)
				break;
			else
			{
				for(int j=i;j<n;j++)
					map.insert(num[i]+num[j]);
			}
		}	
//		cout<<map.size()<<" : "<<(n+1)*n/2<<endl;
		if(map.size()==(n+1)*n/2)
			cout<<"Case #"<<counter++<<": It is a B2-Sequence."<<endl;
		else
			cout<<"Case #"<<counter++<<": It is not a B2-Sequence."<<endl;
		cout<<endl;
	}	
 
}
