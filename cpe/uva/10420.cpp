#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string country,name;
	map<string,int> ans;
	ans.clear();
	int N;
	cin>>N;
	while(N--)
	{
		cin>>country;
		ans[country]++;
		cin.ignore();
		getline(cin,name); 
	}
	map<string,int>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
		cout<<it->first<<" "<<it->second<<endl; 
}
