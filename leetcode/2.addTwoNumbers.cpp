// 題目:
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// ex l1:3->4->7
//    l2:9->7->5->9
//    l3:2->2->3->0->1
//    因為743+9579=10322
//  Definition for singly-linked list.
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0);
        ListNode *r=l3;
        int sum,carry=0;
        while(l1!=NULL&&l2!=NULL)
        {
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            r->next=new ListNode(sum%10);
            r=r->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            sum=carry+l1->val;
            carry=sum/10;
            r->next=new ListNode(sum%10);
            r=r->next;
            l1=l1->next;
        }
         while(l2)
        {
            sum=carry+l2->val;
            carry=sum/10;
            r->next=new ListNode(sum%10);
            r=r->next;
            l2=l2->next;
        }
        if(carry!=0)
            r->next=new ListNode(carry);
        return l3->next;
    }
};
//大神
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//         int carry = 0;
//         ListNode *lres = nullptr;
//         ListNode *head = nullptr;
        
//         while (l1 != nullptr && l2 != nullptr){

//             int res = l1->val + l2->val + carry;
//             ListNode *iter = new ListNode(res%10);
//             if (head == nullptr){
//                 lres = iter;
//                 head = iter;
//             }
//             else{
//                 lres->next = iter;
//                 lres = iter;
//             }
            
//             carry = res/10;
            
//             l1 = l1->next;
//             l2 = l2->next;
//             // lres = lres->next;
//         }
        
//         while(l1 != nullptr){
//             int res = l1->val + carry;
//             ListNode *iter = new ListNode(res%10);
//             carry = res/10;
            
//             lres->next = iter;
//             lres = iter;
//             l1 = l1->next;
//         }
        
//         while(l2 != nullptr){
//             int res = l2->val + carry;
//             ListNode *iter = new ListNode(res%10);
//             carry = res/10;
            
//             lres->next = iter;
//             lres = iter;
//             l2 = l2->next;
//         }
        
//         if (carry){
//             ListNode *iter = new ListNode(carry);
//             lres->next = iter;
//             lres = iter;
//         }
        
//         return head;
//     }
// };