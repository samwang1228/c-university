// link:https://leetcode.com/problems/middle-of-the-linked-list/
// 題目:要回傳linked list的中間位置，如果是偶數個元素則回傳左邊那個
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
// 解法一: 先每個尋訪看是偶數或奇數在做出對應的return
// 解法二: 使用快指針跟慢指針當快指針走完了慢指針剛好是中間(最快)
 
#include<iostream>
#include<string>
#include <sstream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int counter=1;
        ListNode *cur=head;
        bool isOdd=true;
        while(cur)
        {
            counter++;
            cur=cur->next;
        }
        isOdd=(counter & 1) ? false: true;
        int size=(isOdd)? counter/2 : counter/2+1;
        cur=head;
        for (int i=1;i<size;i++)
        {
            cur=cur->next;
        }
        return cur;
    }
};
// 100 %
class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow,*fast;
        fast=slow=head;
        while(fast && fast->next )
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
};