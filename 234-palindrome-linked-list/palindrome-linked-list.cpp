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
    bool isPalindrome(ListNode* head) {
        
        // sc - o(n)

        stack<int>s;
        for(ListNode* curr = head;curr != NULL;curr = curr->next)
        {
            s.push(curr->val);

        }
        for(ListNode* curr = head;curr != NULL;curr = curr->next)
        {
            if(s.top() != curr->val) return false;
            s.pop();
        }
        return true;
    }
};