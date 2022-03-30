#include<iostream>
#include<string> 
#include<map>
#include<vector>
#include<algorithm> 
/*
map用法 map<key type , value type> var
var->first=key
var->second=value
用var[key]來取value

for取值
map<key type , value type>::iterator eachvar
for(eachvar=var.begin();eachvar!=var.end();eachvar)
{
	cout<<eachvar->first //key
	cout<<eachvar->second//value
}
*/
struct List{
	int ascii;
	int freq;
};
bool cmp(List a,List b)
{
	if(a.freq<b.freq)
		return true;
	else if(a.freq==b.freq)
	{
		if(a.ascii>b.ascii)
			return true;
		else
			return false; 
	} 
	else
		return false;
}
using namespace std;
int main() 
{
	string s;
	map<int ,int >table;
	vector<List> ans;
	bool first=true;
	while(getline(cin,s))
	{
		table.clear();
		if(!first)
			cout<<endl;
		else
			first=false;
		ans.clear();
		for(int i=0;i<s.size();i++)
		{
			table[int(s[i])]++;
		} 
		map<int , int >::iterator it;
		for(it=table.begin();it!=table.end();it++)
		{
			List temp;
			temp.ascii=it->first;
			temp.freq=it->second;
			ans.push_back(temp);
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i].ascii<<" "<<ans[i].freq<<endl;
		}
	}
}
