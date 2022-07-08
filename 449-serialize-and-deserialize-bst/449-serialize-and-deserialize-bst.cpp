/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  void dfs(TreeNode* root, string& s)
    {
        if(!root)
        {
            s+= "*";
            return;
        }
        
        s += to_string(root->val) + ",";
        
        dfs(root->left, s);
        dfs(root->right, s);
        
       
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //we need where NULL is occuring in the preorder to get number of nodes and construct the tree hence using *  for all null pointers
        string s = "";
        dfs(root, s); 
        return s;
    }

    TreeNode* decode(string & data)
    {
        if(data[0] == '*')
        {
            data = data.substr(1);
            return NULL;
        }
        
        string no="";
        int pos = 0;
        while(data[pos] != ',')
        {
            no  += data[pos++];
            
        }
        TreeNode* curr = new TreeNode(stoi(no));
        data =  data.substr(pos+1);
        
        curr->left = decode(data);
        curr->right = decode(data);
        
        
        return curr;
        
    }
        
        // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() <= 1) 
            return NULL; // empty tree so string would contain only "*"
        return decode(data);        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;