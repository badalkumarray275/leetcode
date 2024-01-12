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
    private:
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode* rest_head = reverse(head->next);
        ListNode* rest_tail = head->next;
        rest_tail ->next = head;
        head->next = NULL;
        return rest_head;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        // sc - o(1)
        
        ListNode* slow = head,*fast = head;
        while(fast ->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow->next);
        ListNode* curr = head;
        while(rev != NULL)
        {
            if(rev->val != curr->val)return false;
            curr = curr->next;
            rev = rev->next;
        }
        return true;
    }
};