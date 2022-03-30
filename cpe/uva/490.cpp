#include <iostream>
#include<string>
using namespace std;
/*
題目把字串向右(順時針)選轉
ex sam    =>ts
   tina     ia
            nm
            a  
*/
int main()
{
	string s[100]; //不能超過100 line  
	int index=0;
	int max=0;
	while(getline(cin,s[index]))
	{
		if(s[index].size()>max) //找最大長度字串 
			max=s[index].size();
                index++;
		if(index>=100)
			break;
	} 
	for(int i=0;i<max;i++) //左到右 ->上到下 
	{
		for(int j=index-1;j>=0;j--) //每個字串的開頭位置 
		{
			if(s[j].size()<=i) //代表此字串不夠長 要cout 空白 
			{
				cout<<" ";
			}
			else
			{
				cout<<s[j][i];
			}
		} 
		cout<<endl;
	}
}
