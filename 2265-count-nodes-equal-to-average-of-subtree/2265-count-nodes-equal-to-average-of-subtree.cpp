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
    int count;
public:
    
   vector< int> dfs(TreeNode* root)
    {
        if(!root) return {0,0};
        int ans=0;
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
    
        int sum = root->val + left[0] + right[0] ;
       int counter = left[1] + right[1] + 1;
        int avg = sum/counter;
        
        if(root->val == avg)
            count++;
        
        return {sum, counter};
 
        
    }
    int averageOfSubtree(TreeNode* root) {
        
        count = 0;
         dfs(root);
        return count;
    }
};