#include<iostream>
using namespace std;
// 題目:
// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example 1:

// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
// Example 2:

// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
//Note: 1.index=1-n and 是改變index的位置 跟value無關
     // 2.if(head再head->next再head->next->next) 要照順序
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL||head->next==NULL||head->next->next==NULL )
            return head;
        ListNode *oddhead = head;
        ListNode *oddtail = head;
        ListNode *evenhead = head->next;
        ListNode *eventail = head->next;
        ListNode *curr = evenhead->next;
        oddhead->next = curr;
        evenhead->next = curr->next;
        curr->next = evenhead;
        eventail = evenhead->next;
        if(eventail==NULL)
            return head;
        curr = eventail->next;
        oddtail = oddhead->next;
        while(curr!=NULL)
        {
            oddtail->next = curr;
            eventail->next = curr->next;
            curr->next = evenhead;
            eventail = eventail->next;//這裡也是
            oddtail = curr;//這裡很重要
            if(eventail==NULL)
                break;
            curr=eventail->next;
        }
        return head;
    }
};
//找到規律後其實直接oddtail=curr就好
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL||head->next==NULL||head->next->next==NULL )
            return head;
        ListNode *oddtail = head;
        ListNode *evenhead = head->next;
        ListNode *eventail = head->next;
        ListNode *curr = evenhead->next;
        // oddhead->next = curr;
        // evenhead->next = curr->next;
        // curr->next = evenhead;
        // eventail = evenhead->next;
        // if(eventail==NULL)
        //     return head;
        // curr = eventail->next;
        // oddtail = oddhead->next;
        while(curr!=NULL)
        {
            oddtail->next = curr;
            eventail->next = curr->next;
            curr->next = evenhead;
            eventail = eventail->next;
            oddtail = curr;
            if(eventail==NULL)
                break;
            curr=eventail->next;
        }
        return head;
    }