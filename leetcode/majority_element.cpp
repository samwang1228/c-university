#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//題目:
// given an array of size n, find the majority element. 
// The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

//暴力解且第一個i用猜的而非從地一個開始比
int majorityElement(vector<int>& nums) {
        while(true)
        {
            int i=rand()%nums.size();
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                    count++;
            }
            if(count>nums.size()/2)
                return nums[i];
        }
        return 0;
    }

//使用sort接者找中間值因為major element > n/2 用時間換空間
int second(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}     

//演算法1 想法下一個一樣就+1 else -1 當為0則換比新的數
int third(vector<int>& nums)
{
    int num;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(count==0)
        {
            num=nums[i];
            count=1;
        }
        else if(num==nums[i])
            count++;
        else 
            count--;

    }
}                                                             

//演算法2 mid 找左邊跟右邊的最多次在比較
int rangeMajorElement(vector<int>& num,int start ,int end)
{
    if(start==end) return num[start]; 
    int mid=start+(end-start)/2;
    int right_major_element=rangeMajorElement(num,mid+1,end);
    int left_major_element=rangeMajorElement(num,start,mid);
    if(right_major_element==left_major_element) return right_major_element; 
    int leftcount=0;
    for(int i=start;i<=end;i++)
    {
        if(num[i]==left_major_element)
        leftcount++;
    }
    int rightcount=0;
    for(int i=start;i<=end;i++)
    {
        if(num[i]==right_major_element)
        rightcount++;
    }
    if(rightcount>=leftcount)
        return right_major_element;
    return left_major_element;
 }
 int forth(vector<int> &nums)
{
    return rangeMajorElement(nums,0,nums.size()-1);
}                                