#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	bool first=true;
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='"'&&first)
			{
				cout<<"``";
				first=false;
			}
			else if(s[i]=='"'&&!first)
			{
				cout<<"''";
				first=true;
			}
			else
				cout<<s[i];
		}	
		cout<<endl;
	}	
} 
