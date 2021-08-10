#include<iostream>
#include<vector>
#include<string>
// page 3 and leetcode ID 5
//5. Longest Palindromic Substring
//link: https://leetcode.com/problems/longest-palindromic-substring/
// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),
using namespace std;
class Solution {
private:
    int getLength(string s,int l,int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r]) 
        {
             // cout<<"L:"<<l<<" r:"<<r<<" len:"<<r-l-1<<endl;
            l--;
            r++;
            
        }
       // cout<<"ans:"<<r-l-1<<endl;
        return r-l-1; 
    }
public:
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 0;
        if(s.size()==1)
            return s;
        for(int i = 0;i<s.size();i++)
        {
            // cout<<"L"<<endl;
            int l = getLength(s,i,i);
            // cout<<"r"<<endl;
            int r = getLength(s,i,i+1);
            int len = max(l, r);
            if (len > max_len) 
            {
                max_len = len;
                start = i - (len - 1) / 2;
            } 
            // cout<<"test:"<<len<<endl;
        }
        // cout<<"max"<<max_len;
        return s.substr(start,max_len);
        
    }
};