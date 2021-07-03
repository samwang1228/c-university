#include<iostream>//goto找不重複
#include<cstdlib>
#include<ctime>//s,h,d,c
using namespace std;
int issuecard()
{
     return  rand() % 52 + 1;
}
void difficult(int n)
{
    if((n - 1)/13+1==1){
        cout << "S" ;
    }
    else if((n - 1)/13+1==2){
        cout << "H" ;
    }
      else if((n - 1)/13+1==3){
          cout << "D";
    }
      else if((n - 1)/13+1==4){
          cout << "C" ;
    }
      if((n - 1)%13+1==1){
          cout << "A"<<endl ;
    }
    else if((n - 1)%13+1==11){
        cout << "J"<<endl ;
    }
    else if((n - 1)%13+1==12){
        cout << "Q" << endl;
    }
    else if((n - 1)%13+1==13){
        cout << "K"<<endl;
    }
    else {
        cout << (n - 1) % 13 + 1<<endl;
    }
}
int main(){
    int s,x;
    cin>>s>>x;
	int num[x]={};
    srand(s);
    for (int i = 0; i < x;i++){

        start:
        num[i]=issuecard();
	    for(int j=0;j<i;j++)
	    {
	    	if(num[i]==num[j])
	    	{
                goto start;
            }
		}
        difficult(num[i]);
}
}
/*#include<iostream>//do while找不重複
#include<cstdlib>
#include<ctime>//s,h,d,c
using namespace std;
int issuecard()
{
     return  rand() % 52 + 1;
}
void difficult(int n)
{
    if((n - 1)/13+1==1){
        cout << "S" ;
    }
    else if((n - 1)/13+1==2){
        cout << "H" ;
    }
      else if((n - 1)/13+1==3){
          cout << "D";
    }
      else if((n - 1)/13+1==4){
          cout << "C" ;
    }
      if((n - 1)%13+1==1){
          cout << "A"<<endl ;
    }
    else if((n - 1)%13+1==11){
        cout << "J"<<endl ;
    }
    else if((n - 1)%13+1==12){
        cout << "Q" << endl;
    }
    else if((n - 1)%13+1==13){
        cout << "K"<<endl;
    }
    else {
        cout << (n - 1) % 13 + 1<<endl;
    }
}
int main(){
    int num[13]={},a=1;
    srand(5);
    for (int i = 0; i < 13;i++){
     do{
         a = 0;
         num[i] = issuecard();
         for (int j = 0; j < i; j++)
         {
             if (num[i] == num[j])
             {
                 a = 1;
                 break;
             }
		}
     } while (a == 1);
     difficult(num[i]);
}
}
*/
