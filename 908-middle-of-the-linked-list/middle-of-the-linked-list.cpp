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
class Solution {
public:

    // using length of linked list
    ListNode* middleNode(ListNode* head) {

       ListNode* curr = head;
       int count = 0;
       while(curr != NULL)
       {
           count++;
           curr = curr->next;
       }   
       curr = head;
       for(int i = 1;i<=count/2;i++)
       {
          curr = curr->next;
       }
       return curr;
    }
};