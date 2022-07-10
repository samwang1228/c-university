#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_] Hint output (origin-val) of size and 把!=val 的值搬到vector前面
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=val)
                nums[counter++]=nums[i];
        return counter;
    }
};
int main()
{
    Solution result;
    srand(time(0));
    vector<int> input;
    int size = rand() % 100;
    for (int i = 0; i < size;i++)
    {
        input.push_back(rand() % 25);
    }
    int val = rand() % 10;
    int count=result.removeElement(input, val);
    for (int i = 0; i < count;i++)
    {
        cout << input[i]<<"　";
    }
}