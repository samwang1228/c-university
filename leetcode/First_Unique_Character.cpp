#include<iostream>
#include<string>
using namespace std;
//題目
// Given a string, find the first non-repeating character in it and return its index. 
// If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode"
// return 2.

// Note: You may assume the string contains only lowercase English letters.

int firstUniqChar(string s) {
    int counter[26]={ 0 };
    for (int i=0;i<s.size();i++)
    {
        counter[s[i]-'a']++;
    }
    for(int j=0;j<s.size();j++)
    { 
        if (counter[s[j]-'a']==1)
            return j;
    }
     return -1;
 }