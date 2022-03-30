#include<iostream>
#include<cstring>
using namespace std;
int func(string s,int count)
{
	int temp=0;
	for(int i=0;i<s.size();i++)
	{
		temp=temp+s[i]-'0';
	}
	count++;
	if(temp==9)
		return count;
	else if(temp>9)
	{
		return func(to_string(temp),count);
	}
	else
		return 0; 
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="0")
		break;
		int ans=func(s,0);
		if(ans==0)
			cout << s << " is not a multiple of 9.\n";
		else
			cout << s <<" is a multiple of 9 and has 9-degree "<<ans<<'.'<<endl;
	}
}
