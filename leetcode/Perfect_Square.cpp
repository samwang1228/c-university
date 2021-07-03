#include<iostream>
#include<cmath>
using namespace std;
//題目: 找出完美平方數ex 15=false 16=true (4*4)
//偷用sqrt 
bool isPerfectSquare(int num) {
        double cheak=sqrt(num);
        int ans=sqrt(num);
        return cheak==ans;
    }
//不用 sqrt
bool binary(int start,int end,int target)
{
   long long mid=start+(end-start)/2;
    if(start>end)
    {
        return false;
    }
    if(mid*mid==target) 
    {
        return true;
    }
    if(mid*mid<target)
    {
        return binary(mid+1,end,target);
    }
    if(mid*mid>target)
    {
        return binary(start,mid-1,target);
    }
        return false;
}

 bool second(int num)
{
    return binary(1,num,num);
}  