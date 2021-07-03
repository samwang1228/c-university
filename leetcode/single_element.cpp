#include<iostream>
#include<vector>
// You are given a sorted array consisting of only integers where every element appears exactly twice, 
// except for one element which appears exactly once. Find this single element that appears only once.
// Follow up: Your solution should run in O(log n) time and O(1) space.
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int count=0;
        int test=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==test)
            {
                count++;
            }
            if(count>=1&&nums[i]!=test)
            {
                test=nums[i];
                count=0;
            }
        }
        return test;
    }