#include <iostream>//使用者輸入十進位與十六進位數轉成二進位後輸出有幾個一 
using namespace std; 
int main()
{
	int ten,six,n,right;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ten;
		six=ten;
		int b1=0,b2=0;
		while(ten!=0)
		{
			if(ten%2==1) b1++; 
			ten=ten/2;
		}
		cout<<b1<<" ";
		while(six!=0)
		{
			right=six%10;
		while(right!=0)
		{
			if(right%2==1) b2++;
			right=right/2;
		}
		six=six/10;
		}
		cout<<b2<<endl;
	}
	return 0;
}
