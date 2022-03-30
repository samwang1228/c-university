#include<iostream>
//uva11078
//題目 data[i] 為data[i+x] 的senior
//計算max(data[i]-data[i+x]) 
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
			if(senior-next>ans)//用最大的一直減junior 
				ans=senior-next;
			if(next>senior) //用最大去減一定最大 故尋找max(senior) 
				senior=next;
		}	
		cout<<ans<<endl;
	}	
} 
