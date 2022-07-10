#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=0)
                nums[i]+=nums[i-1];
            if(max<nums[i])
                max=nums[i];
        }
        return max;
    }
};