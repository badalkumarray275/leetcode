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
        
        // tc - o(m+n) , sc - o(m)

        unordered_set<ListNode*> s;
        for(ListNode* curr = headA;curr != NULL;curr = curr->next)
        {
            s.insert(curr);
        }
        for(ListNode* curr = headB;curr != NULL;curr = curr->next)
        {
            if(s.find(curr) != s.end()) return curr;

        }
        return NULL;
    }
};