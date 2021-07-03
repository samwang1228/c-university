#include <iostream>
using namespace std;
void merge(int a[], int lo, int mid, int hi) 
{
   int *aux=new int[hi-lo+1];//new space for merge
   int k=lo; 
   for (k = lo; k <= hi; k++) //Copy data to new space
   aux[k-lo] = a[k];
   int  i=lo, j =mid+1; 
  for (k = lo; k <= hi; k++){
      if(i==mid+1){
        a[k]=aux[j-lo];
        j++;
        continue;
      }
      if(j==hi+1){
        a[k]=aux[i-lo];
        i++;
        continue;
      }
    if(aux[i-lo]>aux[j-lo]){
        a[k]=aux[j-lo];
        j++;
    }
    else{
    a[k]=aux[i-lo];
    i++;
    }
  }
    delete [] aux;
}
void rq_sort(int a[], int lo, int hi) 
{ 
    if (hi <= lo){
  return;
 }
    int mid = lo + (hi - lo) / 2; 
    rq_sort(a, lo, mid); //不斷分割 左邊到中間
    rq_sort(a, mid+1, hi); //不斷分割 中間到右邊
    merge(a, lo, mid, hi); 
}
int main(){
 int size;
 cin>>size;
 int* arr;
 arr=new int[size];
 for(int i=0;i<size;i++){
  cin>>arr[i];
 }
 rq_sort(arr,0,size-1);
 int location;
 while(cin>>location){
  if(location<=0){
   break;
  }
  cout<<arr[location-1]<<endl;
 }
 return 0;
}