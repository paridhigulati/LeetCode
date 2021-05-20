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
    
    // find height of tree and reverse 
   int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    void helper(vector<vector<int>> &ans, TreeNode *root,int level){
        if(!root) return;
        ans[level].push_back(root->val);
        helper(ans,root->left,level+1);
        helper(ans,root->right,level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans(height(root));
        helper(ans,root,0);
        reverse(ans.begin(),ans.end());
        return ans;
	}
};