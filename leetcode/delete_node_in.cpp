#include<iostream>
//題目:
// Write a function to delete a node in a singly-linked list. 
// You will not be given access to the head of the list, 
// instead you will be given access to the node to be deleted directly.

// It is guaranteed that the node to be deleted is not a tail node in the list.
// ex:
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after callling your function.
// * Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// temp: 1 
// node: 5         
// after *node=*node->next:node=1            
// Linklist: 4->1  temp->1->9
//              ->9
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;//先把next存起來
        *node=*node->next; //把當前與下一個得node位置相等故此時兩個會同時指向node->next->next
        delete (temp);
        }
};