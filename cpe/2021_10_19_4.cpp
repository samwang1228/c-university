#include<iostream>
using namespace std;
//ÃD¥Ø:input two num --> low!~high! have differ number of zero 
//ex 1!-> 1 none zero : 10!-> 3628800 two zero output 3(0~2)
//stratege 2x5-> generate one zero so caculate number of five and each five cycle generate 5 multiple
int main()
{
	long long int low,high,num_of_lowzero,num_of_highzero;
	while(cin>>low>>high )
	{
		if(low==0 && high==0)
			break;
		num_of_lowzero=0;
		num_of_highzero=0;
		num_of_lowzero=low/5;
		num_of_highzero=high/5;
//		hint : 0->0 =1 so plus 1
		cout<<1+num_of_highzero-num_of_lowzero<<endl; 
	}
	
} 
