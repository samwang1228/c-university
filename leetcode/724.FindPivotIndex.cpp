
// Link:https://leetcode.com/problems/find-pivot-index/
// 題目:當左邊和等於右邊和(皆不包含樞紐)return 樞紐位置，若有n個value可以同時達成pivot要選最左邊那個,若沒有樞紐return -1

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// 解題思路:先算出array的總和，再從index=0的位置減去nums elemebt，以及設一個第二個和來比對來個是否相等。
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res=0,total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            
            total-=nums[i];
            if(res==total)
                return i;
            res+=nums[i];
        }
        return -1;
    }
};