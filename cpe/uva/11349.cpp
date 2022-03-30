#include<iostream>
#include<string>
using namespace std;
/*
2
N = 3
5 1 3
2 0 2
3 1 5 Test #1: Symmetric.
N = 3
5 1 3
2 0 2
0 1 5 Test #2: Non-symmetric.

2
N = 4
1 2 3 4
5 6 7 8
8 7 6 5
4 3 2 1 Test #1: Symmetric.
N = 4
-1 -2 -3 -4
-5 -6 -7 -8
-8 -7 -6 -5
-4 -3 -2 -1 Test #2: Non-symmetric.
Hint:°j¤åÀË´úex 5 1 3 2 0 2 3 1 5
             ex 1 2 2 1 
*/
int main()
{
	int N;
	string s;
	cin>>N;
	int size;
	int t;
	for(int i=1;i<=N;i++)
	{
		cin>>s>>s>>size;
		long long ans[size*size]={0};
		for(int j=0;j<size*size;j++)
		{
			cin>>ans[j];
		}
		for(t=0;t<size*size;t++)
		{
			if(ans[t]!=ans[size*size-1-t]||ans[t]<0)
			{
				break;
			}
		}	
//		cout<<t;
		if(t==size*size)
			cout<<"Test #"<<i<<": Symmetric."<<endl;
		else
			cout<<"Test #"<<i<<": Non-symmetric."<<endl; 
	}		
} 
