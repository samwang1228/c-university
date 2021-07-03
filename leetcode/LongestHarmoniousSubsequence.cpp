#include<vector>
#include<cmath>
#include<algorithm>
//題目:
//找出陣列中相減為1的數的最大set
// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
//ex:
//-3 -3 -2 -1 -1 -1 return 4
//1 2 2 2 3 3 5 7   return 5
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=nums[0];
        int counter=0,max=0;
        int first=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(abs(temp-nums[i])==1&&first!=nums[i])
            {
                first=nums[i];
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[j]==temp||temp-nums[j]==-1)
                        counter++;
                }
                 if(counter>max)
                        max=counter;
                    counter=0;
                 temp=nums[i];
            }
            else 
            {
                temp=nums[i];
            }
            // cout<<endl;
            // cout<<"temp:"<<temp;
        }
        return max;
    }
};
//大神
class Solution2 {
public:
    int findLHS(vector<int>& nums) {
        int res = 0, start = 0, new_start = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[start] > 1) start = new_start; // 相減大於1新的序列
            if (nums[i] != nums[i - 1]) new_start = i; // 不相等新的數
            if (nums[i] - nums[start] == 1) res = max(res, i - start + 1); //用i來計算重複的 
        }
        return res;
    }
};
//1 2 2 3 3 5 7   return 4
// new  :1 1 3 4
// start:0 0 1 3
// res  :2 0 3 3
// i    :1 2 3 4