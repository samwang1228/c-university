#include <iostream>
using namespace std;
int main(){
    int x[5],y[5],sum1=0,sum2=0,max1,min1,max2,min2;
    for(int i=0;i<=4;i++){
        cin >> x[i];
    }
    for(int j=0;j<=4;j++){
        cin >>y[j];
    }
     max1=x[0];min1=x[0],sum1=x[0];
    for(int i=1;i<=4;i++){
        if(max1<x[i]){
        max1=x[i];
    }
        if(min1>x[i]){
            min1=x[i];
        }
        sum1+=x[i];
    }
    max2=y[0];min2=y[0],sum2=y[0];
    for(int j=1;j<=4;j++){
        if(max2<y[j]){
            max2=y[j];
        }
        if(min2>y[j]){
            min2=y[j];
        }
        sum2+=y[j];
    }
    sum1=sum1-max1-min1;
    sum2=sum2-max2-min1;
        if(sum1>sum2){
             cout<<"A";
            }
        else if(sum2>sum1){
             cout<<"B";
            }
            else {
                for(int j=0;j<=4;j++){
                    if(x[j]>y[j]){
                        cout <<"A";
                        break;
                    }
                    else if( y[j]>x[j]){
                        cout <<"B";
                        break;
                    }
                }
            }
return 0;
}