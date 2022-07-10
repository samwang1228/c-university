
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