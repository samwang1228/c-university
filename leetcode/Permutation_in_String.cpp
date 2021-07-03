#include<iostream>
#include<cstring>
using namespace std;
// 題目:
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
// In other words, one of the first string's permutations is the substring of the second string.

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False

bool checkInclusion(string s1, string s2) {
    int counts1['z' - 'a' + 1] = {0};
    int size1 = s1.size();
    int size2 = s2.size();
    if(size1>size2)
        return false;
    for (int i = 0; i < size1;i++)
    {
        counts1[s1[i] - 'a']++;
    }
    for (int i = 0; i < size2-size1+1;i++)
    {
        bool test = true;
        int counts2['z' - 'a' + 1] = {0};
        for (int j = i; j < size1+i;j++)//在s2找s1長度的字串做比較
        {
            counts2[s2[j]-'a']++;
        }
        for (char c = 'a'; c < 'z';c++)
        {
            if(counts2[c-'a']!=counts1[c-'a'])
            {
                test = false;
                break;
            }
        }
        if(test)
            return true;
    }
    return false;
}

//優化 不要每次從頭數
    bool checkInclusion2(string s1, string s2) {
    int counts1['z' - 'a' + 1] = {0};
    int counts2['z' - 'a' + 1] = {0};
    int size1 = s1.size();
    int size2 = s2.size();
    if(size1>size2)
        return false;
    for (int i = 0; i < size1;i++)
    {
        counts1[s1[i] - 'a']++;
    }
      for (int j = 0; j < size1;j++)
        {
            counts2[s2[j]-'a']++;
        }
    for (int i = 0; i < size2-size1+1;i++)
    {
        bool test = true;
        for (char c = 'a'; c < 'z';c++)
        {
            if(counts2[c-'a']!=counts1[c-'a'])
            {
                test = false;
                break;
            }
        }
        if(test)
            return true;
        if(size1+i<size2)//把前一個減掉 並加上下一個 並當s2不爆掉時才執行
        {
            counts2[s2[i] - 'a']--;
            counts2[s2[size1+i] - 'a']++;
        }
    }
    return false;
}