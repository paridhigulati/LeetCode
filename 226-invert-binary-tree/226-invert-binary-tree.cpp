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
    TreeNode* invertTree(TreeNode* root) {
     
        queue<TreeNode*>q;
        
        if(!root) return NULL;
        
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
          
            TreeNode* swp = tmp->left;
            tmp->left = tmp->right;
            tmp->right = swp;
            
            if(tmp ->left)
                q.push(tmp->left);
            if(tmp->right)
               q.push(tmp->right);
        }
        return root;
        
    }
};