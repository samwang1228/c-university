#include<iostream>
#include<cstring>
using namespace std;
// void failure(string& p)
// {
//     int failure[p.size()];
//     // iterative, bottom-up DP
//     for (int i=1, j=failure[0]=-1; i<p.size(); ++i)
//     {
//         // 先試 p[0...i-1] 的「次長的相同前綴後綴」，
//         // 也就是 p[0...failure[i-1]] = p[0...j]。
//         // 再試 p[0...j] 的「次長的相同前綴後綴」，
//         // 也就是 p[0...failure[j]]。
//         // 再試 p[0...failure[j]] 的「次長的相同前綴後綴」……
//         // 直到試成功為止。
//         while (j >= 0 && p[j+1] != p[i])
//             j = failure[j];
 
//         // p[i] 終於有用處了，終於可以加長！
//         if (p[j+1] == p[i]) j++;
 
//         // 得到了 failure[i] 的值！
//         failure[i] = j;
//     }
// }
template <class T>
void swap1(T& x,T& y)
{
     T temp;
     temp=x;
     x=y;
     y=temp;
}
template <class T>
void bubblesort(T *arr,int size)
{
    for (int i = 0; i < size - 1;i++)
    {
        for (int j = 0; j < size - i - 1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template<class T>
void output(T*arr,int size)
{
    for (int i = 0; i < size;i++)
    {
        cout << arr[i]<<" ";
}
}
template<class T>
void select_sort(T *arr,const int size)
{
    for (int i = 0; i < size;i++)
    {
        int k = i;
        for (int j = i+1; j < size;j++)
        {
            if(arr[k]>arr[j])
            {
                k = j;
            }
        }
        swap1(arr[i],arr[k]);
    }
}
int main()
{
    int sum = 0,i,j,k,n=20;
    for (i = 1; i < n;i++)
    {
        for (j = 1; j < i * i;j++)
        {
                for (k = 0; k < j;k++)
                {
                    sum++;
                }
        }
    }
        cout << sum;
}