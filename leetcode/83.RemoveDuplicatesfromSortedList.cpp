// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
// Return the linked list sorted as well.
// input 1->1->2->3->3
// output 1->2->3
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include<iostream>
#include<string>
#include <sstream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *cur=head;
        while(cur && cur->next)
        {
            if(cur->val==cur->next->val)
            {
                ListNode * temp=cur->next;
                cur->next=cur->next->next;
                delete (temp);
            }
            else
                cur=cur->next;
        }
        return head;
    }
};