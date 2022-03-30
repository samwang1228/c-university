#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n1,n2;
	vector<int> ans;
	while(cin>>n1>>n2)
	{
		ans.clear();
		ans.push_back(n1);
		bool flag=false;
		if(n1==0||n2==0||n2==1||n1<n2)
			cout<<"Boring!"<<endl;
		else
		{
			while(n1!=1)
			{
				if(n1%n2==0)
				{
					n1/=n2;
					ans.push_back(n1);
				}
				else
				{
					flag=true;
					break;
				}
			}
			if(flag)
				cout<<"Boring!"<<endl;
			else
			{
				cout<<ans[0]; 
				for(int i=1;i<ans.size();i++)
					cout<<" "<<ans[i];
				cout<<endl;
			}
		}	
	} 
}
