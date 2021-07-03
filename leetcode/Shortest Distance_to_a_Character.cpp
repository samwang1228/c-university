#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 題目:
// Given a string s and a character c that occurs in s, 
// return an array of integers answer where answer.length == s.length and answer[i] 
// is the shortest distance from s[i] to the character c in s.
// 注意:是最短所以前後都要看
// Input: s = "loveleetcode", c = "e"
//ex t不是4而是1因為左邊有e
// Output: [3,2,1,0,1,0,0,1,2,2,1,0]

//暴力搜尋o(n^2):
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        int counter_1=0,counter_2=0,min;
        bool test_1=false,test_2=false;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(s[j]==c)
                {
                    test_1=true;
                    break;
                }
                counter_1++;
            }
            for(int j=i;j>=0;j--)
            {
                if(s[j]==c)
                {
                    test_2=true;
                    break;
                }
                counter_2++;
            }
            if(counter_1>counter_2&&test_2)
                min=counter_2;
            else if(counter_1<counter_2&&test_1)
                min=counter_1;
            else if(test_1)
                min=counter_1;
            else if(test_2)
                min=counter_2;
            counter_1=0;
            counter_2=0;
            test_1=false;
            test_2=false;
            ans.push_back(min);
        }
        return ans;
    }
};
//優化板 o(n)
//1.先找出所有char的位置
//2.設定右邊與左邊
//3.當值跑到右邊的右邊時左邊變成右邊，右邊往下移一格
//4.看左邊的距離與右邊的距離誰小
class Solution2 {
public:
    vector<int> shortestToChar(string s, char c) {
        int size=s.size();
        vector<int>ans(size),adress;
        int left=0,right=0;
        for(int i=0;i<size;i++)
        {
            if(s[i]==c) adress.push_back(i);
        }
        for(int j=0;j<size;j++)
        {
            if(j>adress[right])
            {
                left=right;
                if(right<adress.size()-1)
                    ++right;
            }
            ans[j]=min(abs(adress[right]-j),abs(adress[left]-j));
        }
            
        return ans;
    }
};