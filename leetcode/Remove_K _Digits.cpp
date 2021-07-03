#include<iostream>
#include<string>
using namespace std;
//題目:
// Given a non-negative integer num represented as a string,
// remove k digits from the number so that the new number 
// is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with

// greedy algorithm 
// 1) 好寫
// 2) 看起來有道理
// 3) 難證明
// 想法從左開始比較 如果左大於右拿掉右邊 
// 因為用小的取代大的

//c
char * removeKdigits(char * num, int k){
    if(strlen(num)==k)
       {
           return "0";
       }
       int len = strlen(num) - k + 1;
       for (int i = 0; i < k;i++)
       {
           for (int j = 0; j <strlen(num);j++)
           {  
               if(num[j]>num[j+1]) //因為最後是\0故不會溢位xd
               {//且因\0為結尾故能直接改變size
                   for (int t = j; t < strlen(num);t++)
                   {//將全部往左移
                       num[t] = num[t + 1]; 
                   }
                   break;
               }
           }
       }
       //處理前面有0的
       int i = 0;
       while(num[i]=='0')
       {
           i++;
       }
        if(i==strlen(num))
            return "0";
        for (int j = 0; j < strlen(num);j++)
        {
            num[j] = num[j + i];
        }
        return num;
}

string removeKdigits(string num, int k) {
    string ans = "";                                         // treat ans as a stack in below for loop
    //若為空 =0即為false 
    //ans.back()查詢最後字元 
    //ans.pop_back()刪除最後字元
    //想法每塞一個字元就前後判斷 並如果後面比前面大就刪除
    //如果第一個為0則不用push_back()
    //ex 00127 k=2
    //ans=1 故0無需處理
    for (char c : num) {
        while (ans.length() && ans.back() > c && k) {
            ans.pop_back();                                  // make sure digits in ans are in ascending order
            k--;                                             // remove one char
        }
        
        if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0'
    }
    //這裡為 1234567的情況 若為此情況則刪除最後k個數
    while (ans.length() && k--) { ans.pop_back(); }          // make sure remove k digits in total
    //從這裡
    if(ans.empty())
        return "0";
    return  ans;
    //上面=return ans.empty() ? "0" : ans;
}