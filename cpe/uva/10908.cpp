#include<iostream>
using namespace std;
char ans[100][100];
int h,w;
bool isSqure(int y,int x,int r)
{
	int button=y-r;
	int top=y+r;
	int left=x-r;
	int right=x+r;
	if(button<0||top>=h||left<0||right>=w)
		return false;
	for(int i=button;i<=top;i++)
	{
		for(int j=left;j<=right;j++)
		{
			if(ans[i][j]!=ans[y][x])
				return false;
		}
	}
	return true;
}
int main()
{
	int n,c;
	int y,x;
	cin>>n;
	while(n--)
	{
		cin>>h>>w>>c;
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>ans[i][j];
			}
		}
		for(int i=0;i<c;i++)
		{
			cin>>y>>x;
			int r=1;
			char center=ans[y][x];
			while(isSqure(y,x,r))
			{
				r++;	
			}
			cout<<r*2+1<<endl;	
		}
	}
}
