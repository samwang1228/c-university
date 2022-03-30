#include <iostream>
#include <iomanip>
#include <map> 
//56 
using namespace std;

int main()
{
	string tree;
	map<string, int> cnt;
	int total=0;
	int n;
	cin>>n;
	cin.ignore();//'\n'
	//**用get前要先ignore換行 
	cin.get();//空白行 
	bool first=true;
	while(n--)
	{
		if(!first) cout<<endl; 
		first = false;
		cnt.clear();
		total=0;
		//若為空白行，getline讀到的會是""! 
		while(getline(cin, tree) && tree!="")
		{
			//cnt
			cnt[tree]++;
			//total
			total++;
		}
		//fractional
		map<string, int>::iterator it;
		for(it=cnt.begin(); it!=cnt.end(); it++)
		{
			cout<<it->first;
			//小數4位 
			cout<<fixed<<setprecision(4)<<" "<<(double)(it->second)/(double)total*100.0<<endl;
		}
	}
}
