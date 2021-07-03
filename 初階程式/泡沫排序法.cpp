#include<iostream>
using namespace std;//泡沫排序法 小到大
void input(int *p,int a)
{
     for(int i=0;i<a;i++){
            cin >>p[i];
        }
}
void output(int *p,int a)
{
    for(int i=0;i<a;i++){
            cout << p[i] <<" ";
        }
}
void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
}
 
void selection_sort(int *list, int n)
{
  int min_id;
  for (int i = 0; i < n - 1; i++)
  {
      min_id = i;//把list[0]設位最小
      for (int j = i + 1; j < n; j++)
      {
          if (list[j] < list[min_id])
              min_id = j;//一旦找到後方陣列比自己小的將那個值取代成最小
      }
      swap(list[i], list[min_id]); //送地址過去swap function
  }
}
 void bubble_sort(int *x,int a)
 {
     for (int j = 0; j < a - 1; j++)
     { //一定要減1因為n數最多只比n-1次

         for (int i = 0; i < a - 1 - j; i++)
         { //因為最右方一定為最大不用比故可-j
             if (x[i] >= x[i + 1])
             {
                 swap(x[i], x[i + 1]);
             }
         }
    }
 }
int main(){
    int *x,a;
    string s;
    cin >> a;
    x = (int *)malloc(sizeof(int) * a);//類似new int 
    input(x, a);
    cin >> s;
    if(s=="bubble")
    bubble_sort(x, a);
    else if(s=="selection")
    selection_sort(x, a);
    output(x, a);

    return 0;
}