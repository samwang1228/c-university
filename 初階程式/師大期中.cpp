#include<iostream>
using namespace std;//泡沫排序法 小到大
int main(){
    int x[99],Y[99],a,t,sum1,sum2;
        for(int i=0;i<5;i++){
            cin >>x[i];
        }  
         for(int i=0;i<5;i++){
            cin >>y[i];
        }            
        for(int j=0;j<4;j++){//一定要減1因為n數最多只比n-1次
        
        for(int i=0;i<3-j;i++){//因為最右方一定為最大不用比故可-j
            if(x[i]>=x[i+1]){
                t=x[i];
                x[i]=x[i+1];
                x[i+1]=t;
            }
        }
        } 
        for(int j=0;j<4;j++){//一定要減1因為n數最多只比n-1次
        
        for(int i=0;i<3-j;i++){//因為最右方一定為最大不用比故可-j
            if(y[i]>=y[i+1]){
                t=y[i];
                y[i]=y[i+1];
                y[i+1]=t;
            }
        }
        }
        for(int i=1;i<=3;i++){
            sum1+=x[i];
        }
        for(int j=1;j<=3;j++){
            sum2+=y[j];
        }
        if(sum1>sum2){
                cout<< "A";
        }
        else if(sum2>sum1){
            cout <<"B";
        }
        
return 0;
}