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
//  iterative approach


    // ListNode* reverseList(ListNode* head) {
        
    //  vector<int>arr;
    //   for(ListNode* curr = head;curr != NULL;curr = curr->next)
    //   {
    //       arr.push_back(curr->val);

    //   }
    //   for(ListNode* curr = head;curr != NULL;curr = curr->next)
    //   {
    //       curr->val = arr.back();
    //       arr.pop_back();

    //   }
    //   return head;

    // }

//  using two pointer approach

    // ListNode* reverseList(ListNode* head) {
      
    //   ListNode* prev = NULL;
    //   ListNode* curr = head;

    //  while(curr != NULL)
    //  {
    //      ListNode* temp = curr->next;
    //      curr->next = prev;
    //      prev = curr;
    //      curr = temp;
    //  }
    //  return prev;
         
    // }

//  recursive approach 

     ListNode* reverseList(ListNode* head) {
      
      if(head == NULL || head->next == NULL) return head;

       ListNode* rest_head = reverseList(head->next);
       ListNode* rest_tail = head->next;
       rest_tail->next = head;
       head->next = NULL;
       return rest_head;
    }
};