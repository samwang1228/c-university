#include<stdio.h>
#include<iostream>
using namespace std;
int n[10];
int N,M=1;
void password(int index){ //index代表要填哪一格
int i;
    if(index==N){
        for(i=0;i<N;i++)
            printf("%d",n[i]);
            printf("\n");
        return ;
    }
    for(i=0;i<=M;i++){
        n[index] = i;
        password(index+1);
    }
}
int main( ) {
while(cin>>N)//3 1 N為位數 M為range
{
password(0);
} 
return 0;
}
