#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
// Given a sorted array of distinct integers and a target value, 
// return the index  if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left<=right) {
          int mid = left+(right-left)/2;
          if (nums[mid]>target) {
            right=mid-1;
          } else if (nums[mid]<target) {
            left=mid+1;
          } else {
            return mid;
          }
        }
            return left;
    }
};