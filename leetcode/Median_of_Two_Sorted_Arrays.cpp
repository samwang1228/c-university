#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 題目:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, 
// return the median of the two sorted arrays.

// Follow up: The overall run time complexity should be O(log (m+n)).
// ex:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//此方法光是insert就O(N+M)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        vector<int>nums3;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        if(nums3.size()%2==1) 
        {
            ans=nums3[(nums3.size()-1)/2];
            return ans;
        }
        else 
        {
            ans=nums3[nums3.size()/2]+nums3[nums3.size()/2-1];
            return ans/2;
        }

    }
};
//大神方法之後吧