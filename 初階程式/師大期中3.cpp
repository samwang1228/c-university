#include<iostream>
#include<math.h>
using namespace std;//使用者輸入10進位先轉2並翻轉再轉十進位制
int main(){
    int x,t,n=0,sum=0;
    int y[99];
    cin >> x;
   if(x==0){
       cout <<"0";
   }
   else{
   while(x>0){
    t=x%2;
    y[n]=t;
    x=x/2; 
    if(x==0){
        break;
    }
    n++;
   }
   int p=n;
   for(int i=0;i<=n;i++){
       y[i]=y[i]*pow(2,p);
   sum+=y[i];
   p--;
   }
   cout << sum;
   }    
return 0;
}