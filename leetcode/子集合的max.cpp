//{1,-4,-6,9}則找出連續元素和的最大值ex1-4-6+9 -4-6 1 9接為組合 max=9
#include<iostream>
#include<climits>//INT_MIN
using namespace std;
/*int pior(int *p,int size)//優化
{
    int maxPresubarray[size];
     maxPresubarray[0] = 0;
    for (int i = 1; i < size;i++)
    {
        int notchoose = 0;
        int choose = maxPresubarray[i - 1] + p[i - 1];
        if(notchoose>choose)
        {
            maxPresubarray[i] = notchoose;
        }
        else
        {
            maxPresubarray[i] = choose;
        }
    }
    int choose = maxPresubarray[size - 1] + p[size - 1];
}*/
int premaxsubarry(int *p,int size)//選最後的情況看頭是幾
{
    if(size==0)
        return 0;
    int notchoose = 0;//因為代表連最後都不選故sum==0
    int choose = premaxsubarry(p, size - 1) + p[size - 1];//不斷改變頭
    if(choose>notchoose)
        return choose;
    return notchoose;
}
int maxsubarry(int *p,int size)//最快解法
{  
      if (size == 1)
            return p[0];                    //當size-到剩1代表頭最大
    int notchoose = maxsubarry(p, size - 1);//不選最後 ex{-1,-2,-3,-4,-5}第一次 {-1,-2,-3,-4}第二次{-1,-2,-3}以此類推
    int choose = premaxsubarry(p, size - 1) + p[size - 1];//選最後但不知道頭是多少{O,O,O,O},{X,X,X,O},{X,X,O,O}
    if(choose>notchoose)
        return choose;
    return notchoose;
}

int maxSubarray2(int *nums,int size){ //上次的最大子集合是負數就不選
    int maxNums = nums[0];
    for (int i = 1; i < size;i++)
    {
        if(nums[i-1]>0)
            nums[i] = nums[i] + nums[i - 1];
        maxNums = max(nums[i], maxNums);
    }
    return maxNums;
}
void input(int *a,int size)
{
    for (int i = 0; i < size;i++)
    {
        cin >> a[i];
    }
    cout <<maxSubarray2(a, size);
    // cout<<maxsubarry(a, size);
}

int main()
{
    int *arr, size;
    cin >> size;
    arr = new int[size];
    input(arr, size);
}
/*int sumsubarray(int a[],int size)//基礎解法
{
    int max = INT_MIN;
    for (int i = 0; i < size;i++)//決定頭
    {
        int sum = 0;
        for (int j = i; j < size;j++)//決定尾
        {
            int sum = 0;//爆開解
            for (int k = i; k <= j;k++)
            {
                sum += a[k];
            }
            sum += a[j];//稍微加速 想法加下一個項
            if(sum>=max)
                max = sum;
        }
    }
    return max;
}*/