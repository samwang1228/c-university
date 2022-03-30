#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int temp;
	int max=0;
	while(getline(cin,s))
	{
		int sum=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='0'&&s[i]<='9')
				temp=s[i]-'0';	
			else if(s[i]>='A'&&s[i]<='Z')
				temp=s[i]-'A'+10;
			else if(s[i]>='a'&&s[i]<='z')
				temp=s[i]-'a'+36;
			if(max<temp)
				max=temp;
			sum+=temp;	
		}	
		for(int i=max;i<=62;i++)
		{
			if (!(sum % i)) {
                cout << i + 1 << "\n";
                break;
            }
 
        	if (i == 62)
            	cout << "such number is impossible!\n";
		}
	}	
} 
