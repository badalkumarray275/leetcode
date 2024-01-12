/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // tc - o(m+n) , sc - o(1)

         int c1 =0,c2 = 0;
         for(ListNode* curr = headA;curr != NULL;curr = curr->next)
         {
             c1++;
         }
         for(ListNode* curr = headB;curr != NULL;curr = curr->next)
         {
             c2++;
         }
         int d = abs(c1-c2);
         ListNode* curr1 = headA;
          ListNode* curr2 = headB;
         if(c1>=c2)
         {
              for(int i = 1;i<=d;i++)
              {
                curr1 = curr1->next;
              }
         }
         else
         {
              for(int i = 1;i<=d;i++)
             {
               curr2 = curr2->next;
             }
         }
        
        
         while(curr1 != NULL && curr2 != NULL)
         {
             if(curr1 == curr2) return curr1;
             curr1 = curr1->next;
             curr2 = curr2->next;
         }
         return NULL;
        
       
    }
};