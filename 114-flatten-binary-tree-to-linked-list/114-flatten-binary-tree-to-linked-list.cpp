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
    
        TreeNode* dfs(TreeNode* root) {
        // edge case: childless node
        if (!root->left && !root->right) return root;
            
        if (root->left and !root->right) {
            // first case: only the left branch
           // if (!root->right) {
                // attaching the flattened left branch directly to the right of root
                root->right = root->left;
                // removing the left branch
                root->left = NULL;
                // returning the last node of the new right branch (previous left)
                return dfs(root->right);
            }
            else
            {
                if(root->left and root->right)
                {
            // attaching right to the end of the flatened left branch
          TreeNode* leftTail = dfs(root->left);
            leftTail->right = root->right;
            // attaching the flattened left branch directly to the right of root
            root->right = root->left;
            // removing the left branch
            root->left = NULL;
                }
            }
        // if we do not have a left branch, we can just return the flattened right
        return dfs(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root)
        dfs(root);
    }
};
