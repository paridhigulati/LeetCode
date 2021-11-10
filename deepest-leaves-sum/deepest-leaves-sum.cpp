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
    int sum=0;
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = md(root);
          ms(root, 1, maxDepth);
        return sum;
    }
    int md(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh = md(root->left);
        int rh = md(root->right);
        return (lh>rh)?lh+1:rh+1;
    }
    void ms(TreeNode* root, int curr, int depth)
    {
        if(root!=NULL)
        {
            if(curr==depth)
            {
                sum+=root->val;
            }
            ms(root->left, curr+1, depth);
            ms(root->right, curr+1,depth);
            
        }
        
    }
};