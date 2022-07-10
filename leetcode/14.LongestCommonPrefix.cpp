// Link:https://leetcode.com/problems/longest-common-prefix/
// 題目:找到多個字串中的相同字元，且是從[0]開始判定，若中間一樣則不算
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// 解題思路:先找到字串中的最小size並開始一個個比對，只要其中一組不相等就回傳上次的結果
// 反之就將此字元加入至結果
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize=strs[0].size(),j=0;
        string res="";
        for(int i=1;i<strs.size();i++)
        {
            if(minSize>strs[i].size())
                minSize=strs[i].size();
        }
        while(j<minSize)
        {
            for(int i=0;i<strs.size()-1;i++)
            {
                if(strs[i][j]!=strs[i+1][j])
                    return res;
            }
            res+=strs[0][j];
            ++j;
        }
        return res;
    }
};