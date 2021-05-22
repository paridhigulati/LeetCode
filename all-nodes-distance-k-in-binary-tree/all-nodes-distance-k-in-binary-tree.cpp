/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
     void printsubtree(TreeNode* root, int k)
   {
         vector<int>v;
        //case 1 to find nodes in subtree of target at distance k
        if(root ==NULL || k<0)
        {
            return ;
        }
        if(k==0)
        {
            v.push_back(root->val);
          
        }
        printsubtree(root->left,k-1);
        printsubtree(root->right,k-1);
   }
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  
        vector<int>v;
        if(root==NULL)
            return-1;
        if(root==target)
        {
            printsubtree(root,k);
        return 0;
        }
        int dl = distanceK(root->left,k);
        if(dl!=-1)
        {
            if(dl+1 ==k)
            {
                v.push_back(root->val);
            }
        }
        else{
             printsubtree(root->right,k-dl-2);
        }
        
            distanceK()
        

    }
}; */
      vector<TreeNode*> path;
    bool getpath(TreeNode* root, TreeNode* target)
    {
        if(!root)
        {
            return false;
        }
        if(root==target)
        {
            path.push_back(root);
            return true;
        }
        bool left=getpath(root->left,target);
        if(left)
        {
            path.push_back(root);
            return true;
        }
        bool right=getpath(root->right,target);
        if(right)
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    vector<int> kl;
    vector<int> klevel(TreeNode* root,int k,TreeNode* block)
    {
        if(!root || k<0 || root==block)
        {
            return kl;
        }
        if(k==0)
        {
            kl.push_back(root->val);
        }
        klevel(root->left,k-1,block);
        klevel(root->right,k-1,block);
        return kl;
    }
    vector<int> ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
            /// This is the combination of node to root path and the and k level down question
        // so basically we will first get the node to root path and after getting that we will print k level for target k-1 to its upper node and similarily all the node will print untill k ==0
        // also there is a catch in this question that while printing the k-1 level down  and so on they will print all the level but we don't need all the elements of that level so we will implement a blocker in this case
        bool gtpath=getpath(root,target);
        if(!gtpath)
        {
            return ans;
        }
        // now till here we have fetched the node to root path in the path vector
        // now we need to print the respective k level down for each node and also implamenet the blocker startegy
        for(int i=0;i<path.size() && i<=k;i++)
        {
            if(i==0)
            {
                vector<int> p=klevel(path[i],k,NULL);
                // return p;
                for(auto x:p)
                ans.push_back(x);
            }
            else{
                vector<int> p=klevel(path[i],k-i,path[i-1]);
                // return p;
                for(auto x:p)
                ans.push_back(x);
            }
            kl.clear();
        }
        return ans;
    }
};