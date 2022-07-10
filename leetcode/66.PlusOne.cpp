#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
// Link:https://leetcode.com/problems/plus-one/ 
// 給定一個vector，此vector會把每個位元拆開，ex222->vector={2,2,2]，今天把最後一個array元素+1若超過10要進位
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].
// 1 <= digits.length <= 100
// 0 <= digits[i] <= 9
// digits does not contain any leading 0's.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ++digits[digits.size()-1];
        int carry=0;
        for(int i=digits.size()-1;i>0;i--)
        {
            digits[i]+=carry;
            carry=digits[i]/10;
            if(digits[i]>=10)
            {
                digits[i]%=10;
            }
        }
        digits[0]+=carry;
        if(digits[0]>=10)
        {
            digits.insert(digits.begin(),digits[0]/10);
            digits[1]%=10;
        }
        return digits;
    }
};