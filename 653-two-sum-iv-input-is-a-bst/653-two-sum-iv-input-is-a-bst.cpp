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
    vector<int>v;
    
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        inorder(root);
        int i=0, j=v.size()-1;
      
        while(i<j)
        {
            if(v[i] + v[j] > k)
                j--;
            else if(v[i] + v[j] < k)
                i++;
            else
                return true;
        }
        return false;
    }
    
       
      // check if target-root->Val exist in set
        
        //optimal   do inorder, now 2 pointer on sorted arr
        
        
        
    
};