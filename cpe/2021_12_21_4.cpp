#include<iostream>
//uva11078
//�D�� data[i] ��data[i+x] ��senior
//�p��max(data[i]-data[i+x]) 
using namespace std;
int main()
{
	int T;
	cin>>T;
	int num;
	int next,ans,senior;
	while(T--)
	{
		cin>>num;
		cin>>senior;
		ans=-1000000;
		for(int i=1;i<num;i++)
		{
			cin>>next;
			if(senior-next>ans)//�γ̤j���@����junior 
				ans=senior-next;
			if(next>senior) //�γ̤j�h��@�w�̤j �G�M��max(senior) 
				senior=next;
		}	
		cout<<ans<<endl;
	}	
} 
