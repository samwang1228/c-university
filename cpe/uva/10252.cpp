//36
//注意這題 只要字串x可"排列"成 s1, s2的子字串就行，不用考慮x排成的s1子字串 是否和s2排成的子字串順序相同
//x字串中的字母可有重複
/*
去你的
翻譯:去找s1跟s2同時存在的字元且這個字元要輸出較小的次數
output要照字母大小 小到大
input 1 2為一組 3 4為一組 
ex s1=samsam
   s2=samsam
   ans=aammss
   
   s1=samsam
   s2=sam
   ans=ams 因為在s2中sam只出現一次 
*/
#include <iostream>

using namespace std;

int main()
{
	string s1, s2;
	while(getline(cin, s1))	//*這裡使用getline是因為輸入包含"空字串"!!! 
	{
		getline(cin, s2);
		int c1[26]={0};	//s1中各字母出現次數 
		int c2[26]={0}; //s1中各字母出現次數
		
		//出現次數統計中		
		for(int i=0; i<s1.length(); i++)
		{
			s1[i]=tolower(s1[i]);
			c1[s1[i]-'a']++;
		}
		for(int i=0; i<s2.length(); i++)
		{
			s2[i]=tolower(s2[i]);
			c2[s2[i]-'a']++;
		}
		
		//依字母順序輸出 
		for(int i=0; i<26; i++)
		{
			int num=c1[i]>c2[i]?c2[i]:c1[i];	//取各字母 出現次數較"少"者 
			for(int j=0; j<num; j++)
				cout<<(char)(i+'a');	//輸出字母
		}
		cout<<endl;	
	}	
} 
