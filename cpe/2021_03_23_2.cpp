#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int cou_num=0,cou_c=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='A'||s[i]=='B'||s[i]=='C')
			{
				cou_num++;
				cout<<2;
			}
			else if(s[i]=='D'||s[i]=='E'||s[i]=='F')
			{
				cou_num++;
				cout<<3;
			}
			else if(s[i]=='G'||s[i]=='H'||s[i]=='I')
			{
				cou_num++;
				cout<<4;
			}
			else if(s[i]=='J'||s[i]=='K'||s[i]=='L')
			{
				cou_num++;
				cout<<5;
			}
			else if(s[i]=='M'||s[i]=='N'||s[i]=='O')
			{
				cou_num++;
				cout<<6;
			}
			else if(s[i]=='P'||s[i]=='Q'||s[i]=='R'||s[i]=='S')
			{
				cou_num++;
				cout<<7;
			}
			else if(s[i]=='T'||s[i]=='U'||s[i]=='V')
			{
				cou_num++;
				cout<<8;
			}
			else if(s[i]=='W'||s[i]=='X'||s[i]=='Y'||s[i]=='Z')
			{
				cou_num++;
				cout<<9;
			}
			else if(s[i]=='0')
			{
				cout<<0;
			}
			else if(s[i]=='1')
			{
				cout<<1;
			}
			else if(s[i]=='-')
			{
				cou_c++;
				cout<<'-';
			}
		}
		cout<<' '<<cou_num<<' '<<cou_c<<endl;
	}	
} 
