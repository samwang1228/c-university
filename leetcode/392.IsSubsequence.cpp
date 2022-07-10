// link:https://leetcode.com/problems/is-subsequence/ 
// 題目:給定兩字串s、t(皆為小寫)，若t的子字串等於s則return true，反之return false
// 子字串的意思是可以拿掉t中的任意字元所組合成的情況，且每個字元皆為獨立
// ex aa可以指移除一個a 子字串=a

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Input: s = "axc", t = "ahbgdc"
// Output: false
// 解題思路:只要s[j]==t[i]就將其字元加入result，再比對result是否等於s就好，但要注意s比較短因此index要另外設
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<map>
using namespace std;
// 使用map 較差
class Solution {
public:
    bool isSubsequence(string s, string t) {
        string res="";
        int counter=0;
        for(int i=0;i<t.size();i++)
        {
            if(counter==s.size())//代表子字串已形成無須繼續比對
                break;
            if(s[counter]==t[i])
            {  
                res+=t[i];
                counter++;
            }
                
        }
        return (res==s);
    }
};