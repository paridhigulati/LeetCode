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
    
    
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>&mp )
    {
  if(is > ie || ps > pe) return NULL;
        TreeNode* root = new TreeNode( postorder[pe]);
        int inr =  mp[postorder[pe]];
        
        int countL = inr -  is;
        
       
        
        root->left =  build(inorder, is, inr-1, postorder, ps, ps + countL-1, mp );
        root->right = build(inorder, inr+1, ie, postorder, ps + countL, pe-1,mp );
        
        return root;
       

        
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>mp;
        if(inorder.size()!= postorder.size())  return NULL;

        for(int i=0;i<inorder.size();i++)
        mp[inorder[i]] =  i;
        
        return build(inorder, 0, inorder.size()-1,postorder, 0, postorder.size()-1 , mp);
    }
};