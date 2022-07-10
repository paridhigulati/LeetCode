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
    
    void dfs(TreeNode* root, int sum,vector<int> tmp, vector<vector<int>>& ans)
    {
        if(!root) return;
       // vector<int>tmp;
        
        if(!root->left and !root->right and sum-root->val == 0)
        {
            tmp.push_back(root->val);
            ans.push_back(tmp);
            return ;
        }
        tmp.push_back(root->val);
        
        dfs(root->left, sum-root->val,tmp, ans);
        dfs(root->right, sum-root->val,tmp, ans);
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>tmp;
         dfs(root, targetSum, tmp , ans);
        return ans;
    }
};

