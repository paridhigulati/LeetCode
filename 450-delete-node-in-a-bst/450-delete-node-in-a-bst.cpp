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
    
   	int max(TreeNode *root){
		TreeNode *curr=root;
		while(curr->left){
			curr=curr->left;
		}
		return curr->val;
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		   if(!root) return root;
		   if(root->val==key){
				 // leaf node
				  if(!root->left && !root->right){
					   return nullptr;
				  }
				 // one child node
				 else if(root->left && !root->right) return root->left;
				 else if(!root->left && root->right) return root->right;
				 //two child node
				 else{
					 //take min value from right subtree or you can take max from left
					 int t=max(root->right);
					 root->val=t;
					 root->right=deleteNode(root->right,t);
				 }
		   }
		   if(key<root->val)
			 root->left=deleteNode(root->left,key);
		   else root->right=deleteNode(root->right,key);
		return root;
	}
};