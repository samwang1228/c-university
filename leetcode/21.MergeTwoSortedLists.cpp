// link:https://leetcode.com/problems/merge-two-sorted-lists/
// 把兩個以排序好的linked list合併
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Input: list1 = [], list2 = [0]
// Output: [0]
// 解題思路:兩個list筆大小把小的放入答案中，且要一個head指向答案的頭
// 每放進一個就在往下比對
 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(0),*res= &head;
        while(list1&&list2)
        {
            if(list1->val<list2->val)
            {
                res->next=list1;
                list1=list1->next;
            }
            else 
            {
                res->next=list2;
                list2=list2->next;
            }
            res=res->next;
        }
        if(list1)
        {
                res->next=list1;
                list1=list1->next;  
        }
        if(list2)
        {
                res->next=list2;
                list2=list2->next;  
        }
        return head.next;
    }
};