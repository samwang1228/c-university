// link:https://leetcode.com/problems/linked-list-cycle-ii/ 
// 要回傳環狀的起始點若沒有環則回傳NULL
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// 解題思路:是否有環用一個快指針跟慢指針去比較如果一樣代表有環，想像一下跑操場，我倒追你一圈
// 怎麼找到起點呢?
 
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        if(!fast ||!fast->next )
            return NULL;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(!fast || !fast->next)
            return NULL;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};