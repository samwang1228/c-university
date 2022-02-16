#include<iostream>
#include<string>
using namespace std;
int main()
{
//	Hint '\' --> '\\' else not found 
	string dic="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	int N=0,counter=0;
	cin>>N; 
	string ans[N];
	cin.ignore(); //Not pull in foor loop
	for(int i=0;i<N;i++)
	{
		string s;
		getline(cin,s);
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				s[i]+=32;
			int pos=dic.find(s[i]);
//			cout<<pos<<" :"<<dic[pos-2];
			if(pos!=-1)
				s[i]=dic[pos-2];
		}
//		cout<<s<<endl;
		ans[counter++]=s;
	}
	for(int i=0;i<N;i++)
	{
		cout<<ans[i]<<endl;
	} 
}
	
  
