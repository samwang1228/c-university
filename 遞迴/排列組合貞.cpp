#include <iostream>
using namespace std;
void swap(int &a ,int &b)
{
 int temp=a;
 a=b;
 b=temp;
}
void permutation(int arr[],int b[],bool f[],int m,const int n)
{
 if (m==n)
 {
  for (int i =0;i<n;i++){
   cout<<(char)b[i];
  }
  cout<<endl;
 }
 else{
   for (int i =0;i<n;i++)
   {
    if (f[i])
    continue;
    f[i]=true;
    b[m]=arr[i];
    permutation(arr,b,f,m+1,n);
    f[i]=false;
   }
  }
}
int main ()
{
 int array[26];
 int index=-1;char symbol;
 while(cin.get(symbol)){
  int test=(int)symbol;
  if(symbol=='\n'){
   break;
  }
  else/* if(test<=122 && test>=97)*/{
   index=index+1;
   array[index]=test;
  }
 }
 //總共有0~index編號的字母們[0][1]...[index] 
 for(int i=0;i<index;i++){
  for(int j=0;j<=index-1-i;j++){
   if(array[j]>array[j+1]){
    char temp=array[j+1];
    array[j+1]=array[j];
    array[j]=temp;
   }
  }
 }
 int b[index+1];
 bool flag[index+1]={false};
 permutation(array,b,flag,0,index+1);
 return 0;
}