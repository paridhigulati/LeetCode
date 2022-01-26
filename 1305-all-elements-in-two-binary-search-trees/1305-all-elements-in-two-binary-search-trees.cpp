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
    
    void dfs(TreeNode* root, vector<int>& ans)
    {
        
        if(!root) return;
        
        ans.push_back(root->val);
        if(root->left) dfs(root->left, ans);
        if(root->right) dfs(root->right, ans);
        
        
        
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
     
        vector<int>ans;
        if(!root1 and !root2)
            return ans;
        
        dfs(root1, ans);
        dfs(root2, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
};