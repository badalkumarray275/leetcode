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

//  iterative soln
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>s;
        s.push(root);
        vector<int>pre;
        if(root == NULL) return pre;

        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            pre.push_back(node->val);
            if(node->right != NULL) 
            {
                   s.push(node->right);
            }
            if(node->left != NULL)
            {
                s.push(node->left);
            }
        }
        return pre;
    }
};