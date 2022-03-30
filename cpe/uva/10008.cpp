#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cctype> //toupper
#include<algorithm> 
using namespace std;
struct dataType{
	char k;
	int v;
};
bool cmp(dataType a,dataType b)
{
	if(a.v>b.v)
		return true;
	else if(a.v==b.v)
	{
		if(a.k<b.k)
			return true;
		else 
			return false;
	} 
	else 
		return false;
}
int main()
{
	int N;
	cin>>N;
	map<char,int> table;
	vector<dataType> ans;
	cin.ignore();
	string s;  
	while(N--)
	{
		getline(cin,s);
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='A'&&s[i]<='Z' || s[i]>='a'&&s[i]<='z')	//為英文字母才統計
			{
				s[i]=toupper(s[i]);
				table[s[i]]++;
			}
		}
	} 
	map<char , int>::iterator it;
	for(it=table.begin();it!=table.end();it++)
	{
		dataType temp;
		temp.k=it->first;
		temp.v=it->second;
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].k<<" "<<ans[i].v<<endl;
}
