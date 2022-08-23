// link:https://leetcode.com/problems/longest-palindrome/
// 題目:給定一個str若此str可以形成回文字串(就是左右對齊ex cac azoza)則回傳最長的回文字串長度
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 解題思路:計算char次數後，如果對應的字元出現偶數次代表能形成偶數長度(前後插入)，如果是奇數將其減1變成偶數
// 並且若有奇數長度是可以加一的(放在中間)
#include<iostream>
#include<string>
#include <sstream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
// TTL
class Solution {
public:
    int longestPalindrome(string  s) {
        vector<int> counter(128,0);
        for(const char c:s)
        {
            ++counter[c];    
        }
        int res=0,odd=0;
        for(const int count:counter)
        {
            // 很多方法
            // res+=count & 1 ? count-1:count;
            // res+=(count>>1)<<1;
            res+=count&(~1);
            if(count&1)
                odd=1;
        }
        res+=odd;
        return res;
    }
};