#include <iostream>
#include<string>
using namespace std;
/*
�D�ا�r��V�k(���ɰw)����
ex sam    =>ts
   tina     ia
            nm
            a  
*/
int main()
{
	string s[100]; //����W�L100 line  
	int index=0;
	int max=0;
	while(getline(cin,s[index]))
	{
		if(s[index].size()>max) //��̤j���צr�� 
			max=s[index].size();
                index++;
		if(index>=100)
			break;
	} 
	for(int i=0;i<max;i++) //����k ->�W��U 
	{
		for(int j=index-1;j>=0;j--) //�C�Ӧr�ꪺ�}�Y��m 
		{
			if(s[j].size()<=i) //�N���r�ꤣ���� �ncout �ť� 
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
