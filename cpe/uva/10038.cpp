#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	int n;
	map<int,int> ans;
	int temp; 
	int f,s;
	while(cin>>n)
	{
		cin>>f;
		for(int i=1;i<n;i++)
		{
			cin>>s;
			temp=abs(f-s);
			ans[temp]++; 
			f=s;
//			cout<<temp<<endl;
		}	
		map<int,int>::iterator it;
		for(it=ans.begin();it!=ans.end();it++)
		{
			if(it->first>n-1||it->second>1)
			{
				break;
			}
		}
		if(it!=ans.end())
			cout<<"Not jolly\n";
		else
			cout<<"Jolly\n";
		ans.clear();
		
	}	

} 
