// Link: https://leetcode.com/problems/valid-parentheses/submissions/ 
// 題目:Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
// 就是今天最後一個右開='('則下一個左開一定要=')'
 
// Input: s = "{[]}"
// Output: true
// Input: s = "{[}]"
// Output: false
#include<iostream>
#include<string.h>
#include <sstream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else 
        {
            if(st.empty()){
                return false;
            }
            else if((c == ')'&&st.top()!='(')||(c == '}'&&st.top()!='{')||(c == ']'&&st.top() != '['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}
};

// class Solution:
//     def isValid(self, s: str) -> bool:
//         stack = []
//         dic = {']':'[', ')':'(', '}':'{'}
//         for c in s:
//             if c not in dic:
//                 stack.append(c)
//             else:
//                 if not stack or stack.pop() != dic[c]:
//                     return False
//         return stack == []