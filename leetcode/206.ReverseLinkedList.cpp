// link:https://leetcode.com/problems/reverse-linked-list/
// 把linked list的位置反轉
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Input: head = [1,2]
// Output: [2,1]
// 解題思路:把下一個位置指向前一個，所以要有一個ptr紀錄前一個，此外當前的下一個or當前需要紀錄
//為了swap
 
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL;
        while(head)
        {
            ListNode *next=head->next; //紀錄下一個
            head->next=pre; //重點將下一個指回上一個
            pre=head;//指完後pre往下
            head=next;//cur指向下一個這裡不能用head->next因為head->next已經等於pre了
        }
        return pre;
    }
};
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL,*curr=NULL;
        while(head)
        {
            prev=curr;//上一個往下指
            curr=head;//紀錄當前
            head=head->next;//當前往下
            curr->next=prev;//當前的下一個等於上一個
        }
        return curr;
    }
};