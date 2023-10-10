/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

// using single stack
    vector<int> postorderTraversal(TreeNode* root) {
        

         TreeNode* curr = root;
         vector<int>pos;
         if(root == NULL) return pos;

         stack<TreeNode*>s;
         while(curr != NULL || !s.empty())
         {
             if(curr != NULL)
             {
                 s.push(curr);
                 curr = curr->left;
             }
             else
             {
                 TreeNode* temp = s.top()->right;
                 if(temp == NULL)
                 {
                     temp = s.top();
                     s.pop();
                     pos.push_back(temp->val);

                     while(!s.empty() && temp == s.top()->right)
                     {
                         temp = s.top();
                        s.pop();
                        pos.push_back(temp->val);
                     }
                 }
                 else
                 {
                     curr = temp;
                 }
             }
         }

         return pos;
    }
};