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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
     
        if(!root1) return root2;
        if(!root2) return root1;
        stack<TreeNode*>st, stt;
        st.push(root1);
        stt.push(root2);
        
        while(!st.empty())
        {
            auto t1 = st.top();
            st.pop();
            auto t2 = stt.top();
            stt.pop();
            
            t1->val += t2->val;
            
            if(!t1->left and t2->left)
                t1->left = t2->left;
            
            else if(t1->left and t2->left)
            {
                st.push(t1->left);
                stt.push(t2->left);
                }
                  
            if(!t1->right and t2->right)
                t1->right = t2->right;
            
            else if(t1->right and t2->right)
            {
                st.push(t1->right);
                stt.push(t2->right);
                }
        }
return root1;
        }
    };

        
        
        
      
         