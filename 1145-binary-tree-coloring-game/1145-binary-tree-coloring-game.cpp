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
    
    
    // Given that total nodes are n.*
// For any node x,
// a.find the count of nodes in the left subtree
// b.and the count of nodes in the right subtree
// c.Count of nodes above node x(remaining tree) will be n-(a)-(b)-1
// If player 2 picks the right child, the right subtree is blocked for player 1
// If he picks the left child, the left subtree is blocked.Similary on picking the parent node, the remaining nodes are blocked
// Condition for player 2 to win:
// a>b+c or b>a+c or c>a+b*
    
    int count(TreeNode* root)
    {
        if(!root) return 0;
        
        return 1 + count(root->left) + count(root->right);
    }
    TreeNode* find(TreeNode* root,  int x)
    {
        if(!root) return NULL;
        if(root->val == x) return root;
        
        TreeNode* left = find(root->left, x);
        TreeNode* right = find(root->right, x);
        
        if(!right) return left;
        
        return right;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
      
        TreeNode* xPos = find(root, x);
        
        int a = count(xPos->left );
        int b = count(xPos->right);
        
        int c = n - a-b-1;
        
        if(a+b < c) return true;
        if(b+c < a) return true;
        if(c+a < b) return true;
        
        return false;
    }
};
















































