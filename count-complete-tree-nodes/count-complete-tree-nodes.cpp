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
 //   int countNodes(TreeNode* root) {
      /*    return !root? 0 : 1 + countNodes(root->left) + countNodes(root->right);
      
      this brute force method where tc = o(n) but in case of complete binary tree, we have h = logN and hence O(h) SC
      
    }
};

APPLYING PROPERTY OF COMPLETE BINARY TREE 
 WE HAVE 1 TO 2^h NODES AT MAX 
 so 1 + (left subtree nodes) + (right subtree nodes)
 */
      int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
   int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
  
};
  // O(LOG2^N)        