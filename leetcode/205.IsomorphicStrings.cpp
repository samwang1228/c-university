// link:https://leetcode.com/problems/isomorphic-strings/
// 題目:給定兩字串s、t，若s把字串替換能得到t則return true,反之return false
// 一個char僅限替換成另一個char，因此出現頻率要一樣，且s.size()=t.size()
// Input: s = "egg", t = "add"
// Output: true
// Input: s = "foo", t = "bar"
// Output: false
// Input: s = "paper", t = "title"
// Output: true
// 解題思路:只要找到該字元最後出現的位置即可，再進行一一比對
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<map>
using namespace std;
// 使用map 較差
class Solution
{
public:
    bool isIsomorphic(string s, string t) {
        map<char,int>counter1;
        map<char,int>counter2;
        for(int i=0;i<s.size();i++)
        {
            counter1[s[i]]=i;
            counter2[t[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            if(counter1[s[i]]!=counter2[t[i]])
                return false;
        }
        return true;
    }
};
// 使用char array較好
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        char c1[256]={0};
        char c2[256]={0};
        for(int i=0;i<s.size();i++)
        {
            c1[s[i]]=i;
            c2[t[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            if(c1[s[i]]!=c2[t[i]])
                return false;
        }
        return true;
    }
};
// best
class Solution3 {
public:
    bool isIsomorphic(string s, string t) {
        char c1[256]={0};
        char c2[256]={0};
        for(int i=0;i<s.size();i++)
        {
            if(c1[s[i]]!=c2[t[i]])
                return false;
            c1[s[i]]=i+1; //要+1是為了aa ab的情況
            c2[t[i]]=i+1; //因為第一個index=0這樣會跟初始化的0起衝突
        }
        return true;
    }
};