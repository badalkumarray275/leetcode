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
    bool hasCycle(ListNode *head) {
        
        // --> with tc 0(n) and sc 0(1)

    // ListNode* temp = new ListNode();
    // ListNode* curr = head;
    // while(curr != NULL)
    // {
    //     if(curr->next == NULL)return false;
    //     if(curr->next == temp)return true;
    //     ListNode* next = curr->next;
    //     curr->next = temp;
    //     curr = next;
        
    // }
    // return false;


    //  -- with sc 0(n)

        unordered_set<ListNode*>s;
        for(ListNode* curr = head;curr != NULL;curr = curr->next)
        {
            if(s.find(curr) != s.end()) return true;
            s.insert(curr);
        }
        return false;
        
    }
};