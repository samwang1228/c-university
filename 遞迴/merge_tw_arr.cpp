#include <iostream>
using namespace std;
void merge(int a[], int lo, int mid, int hi) 
{
    int left_index = mid - lo+1 ; //因為要多出一個空間讓最後插入max
    int right_index = hi-mid;
    int *left_ptr= new int[left_index];
    int *right_ptr = new int[right_index];
    for (int i = 0; i < left_index;i++)
        left_ptr[i] = a[lo + i];
    for (int j = 0; j < right_index;j++)
        right_ptr[j] = a[mid + j+1];//右邊從mid+1開始
    left_ptr[left_index] = 2147483647;//將邊界設為最大這樣就能全部直接比完
    right_ptr[right_index] = 2147483647;
    int min_left = 0, min_right = 0;
    for (int k = lo; k <= hi;k++)//注意有插入一個max故為<=
    {
        if(left_ptr[min_left]>right_ptr[min_right])
        {
            a[k] = right_ptr[min_right];
            min_right++;
        }
        else if(left_ptr[min_left]<=right_ptr[min_right])
        {
            a[k] = left_ptr[min_left];
            min_left++;
        }
    }
    delete[] right_ptr;
    delete[] left_ptr;
}
void rq_sort(int a[], int lo, int hi) 
{ 
    if (hi <= lo){
  return;
 }
    int mid = lo+ (hi - lo) / 2; 
    rq_sort(a, lo, mid); 
    rq_sort(a, mid+1, hi); 
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
 for (int i = 0; i < size;i++)
 {
     cout << arr[i]<<" ";
 }
     int location;
 while(cin>>location){
  if(location<=0){
   break;
  }
  cout<<arr[location-1]<<endl;
 }
 return 0;
}