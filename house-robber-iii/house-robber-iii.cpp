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
 struct housePair
    {
        int withRob = 0;
        int withoutRob = 0;
    };
class Solution {
private:   
   
        housePair robber(TreeNode* root)
        {
            if(root==NULL)
           return housePair{0,0};
            housePair lchild = robber(root->left); //(p) iss faith ke sath call lagaya ki             with robbery kitna max aur w/o rob kitna max amnt
            housePair rchild = robber(root->right); // (q)
            
            //ab jo curr node hai uske pas 2 options 
            //1. rob usko kare so root->val + lchild.q + rchild.q
            int rob =root->val + lchild.withoutRob + rchild.withoutRob;
            //2. rob na kare, max(lchild.p, lchild.q) + max(rchild.
            int notRob = max(lchild.withRob, lchild.withoutRob) + max(rchild.withRob,             rchild.withoutRob);
            
            return housePair{rob,notRob};
        }

public:
    int rob(TreeNode* root) {
      housePair res = robber(root);
        return max(res.withRob, res.withoutRob); 
    }
};
