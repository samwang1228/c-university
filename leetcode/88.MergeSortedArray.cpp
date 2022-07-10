// https://leetcode.com/problems/merge-sorted-array/
// 題目:nums1到m前有個sorting array，nums2到n前有個sorting array,nums1的size等於m+n，大於m後皆array elememt等於0
// 要將兩個array merge成一個大個sorting array
// input:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1 
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>

using namespace std;
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i1=0,i2=0;
        while(i1<m&&i2<n)
        {
            if(nums1[i1]<=nums2[i2])
            {
                ans.push_back(nums1[i1++]);
            }
            else
            {
                ans.push_back(nums2[i2++]);
            }
        }
        if(i1<m)
        {
            for(int i=i1;i<m;i++)
                ans.push_back(nums1[i1++]);
        }
        if(i2<n)
        {
            for(int i=i2;i<n;i++)
                ans.push_back(nums2[i2++]);
        }
        for(int i=0;i<ans.size();i++)
        {
            nums1[i]=ans[i];
        }
    }
};

class Solution2 {
 public :
     void merge(vector< int >& nums1, int m, vector< int >& nums2, int n) {
         int i = m - 1 , j = n - 1 , k = m + n - 1 ;
         while (j >= 0 ) {
            if(i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
         }
    }
};