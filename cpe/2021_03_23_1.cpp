#include<iostream>
using namespace std;
//hiht 2011 1/1為星期六 
int main()
{
	int m_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char week[10][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int n,mm,dd,total;
	cin>>n;
	while(n--){
		cin>>mm>>dd;
		total=4;//因為week[4+1]=星期六 ,1=dd
		for(int i=1;i<mm;i++) //if 3月只要加1 2月剩下的+day 
		{
			total+=m_day[i-1];
		}
		cout<<week[(total+dd)%7]<<endl;
	}
} 
