// 題目
// link:https://leetcode.com/problems/roman-to-integer/
// 把對應的字元轉成文字並相加
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//且有些字元在特定字元前代表意義不同
// I can be placed before V (5) and X (10) to make 4 and 9. ex IV=4 IX=9 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// 輸入
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// hint:我們可以發現當前一個字元大於自己就要減去前一個，反之就直接相加
// 舉例: XL 代表L-X -> 50-10 因為10(X前一個)<50(L當前) 反之 LX=60 -> 10+50 因為50(L前一個)>10(X當前)
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {//不使用map
        int counter=getValue(s[s.size()-1]);
        // int counter=0;
        for(int i=s.size()-1;i>0;i--)
        {
            if(getValue(s[i])>getValue(s[i-1]))
                counter-=getValue(s[i-1]);
            else 
                counter+=getValue(s[i-1]);
        }
        return counter;
    }
    int getValue(char c)
    {
        if(c=='I') return 1;
        else if (c=='V') return 5;
        else if (c=='X') return 10;
        else if (c=='L') return 50;
        else if (c=='C') return 100;
        else if (c=='D') return 500;
        else  return 1000;
    }
};
class Solution2 {//使用map
public:
    int romanToInt(string s) {
        map<char,int>res={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int counter=res[s[s.size()-1]];
        // int counter=0;
        
        for(int i=s.size()-1;i>0;i--)
        {
            if(res[s[i]]>res[s[i-1]])
                counter-=res[s[i-1]];
            else 
                counter+=res[s[i-1]];
        }
        return counter;
    }
   
};