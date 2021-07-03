#include<iostream>
#include<vector>
// page 2 and leetcode ID 3
//link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Example 4:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector < int > index( 128 , - 1 );
         int res = 0 , left = - 1 ;
         for ( int i = 0 ; i < s.size(); ++ i) {
            left = max(left, index[s[i]]);
            index[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};