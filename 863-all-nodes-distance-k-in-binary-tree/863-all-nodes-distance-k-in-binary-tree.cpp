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
    

       	// Recursive Function to get the "parents hash" where child->parent relationship is kept
    void fill_parents(unordered_map <TreeNode*, TreeNode*>& parents, TreeNode* node){    
        if (node == NULL)
            return;
        // store the child->parent relationship and iterate for the left child
        if(node->left != NULL){
            parents[node->left] = node;
            fill_parents(parents, node->left);
        }
        // store the child->parent relationship and iterate for the right child
        if(node->right != NULL){
            parents[node->right] = node;
            fill_parents(parents, node->right);
        }
    }
    
    // Function to get all nodes which are a distance K from target node.
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL)
            return {};
        
        unordered_map <TreeNode*, TreeNode*> parents;
        // Get the child->parent relationship in the "parents" map.
        fill_parents(parents, root);
        
        // Hash to store the nodes which are already visited so we do not fall in an infinite loop
        unordered_map<TreeNode*, bool> visited;

        // Queue for BFS
        queue<TreeNode*> q;

        int currentLevel = 0;
        q.push(target);
        visited[target] = true;
        
        // Till the queue is empty
        while(!q.empty()){

        	// If we are already at level 'K', then we break since queue will have our distance K nodes
        	// otherwise increase the level
        	if (currentLevel == K){
                break;
            }
            currentLevel++;

        	// Get the size of the queue.
            int size = q.size();
            
            // For the size number of elements in the queue, keep trying to visit them and push in the queue
            // This is needed because this will tell us the number of nodes which are at the same level.
            // This is really important to understand that when the control comes here the number of elements
            // in the queue are all at the same level. While the loop runs, it may increase but the 'size' 
            // variable is still the same and it will stop. The new nodes which are added are all at the same level.
            // NOTE:  Putting NULL marker after the level ends will not work here.
            for(int i=0; i<size; i++) {
                TreeNode* front = q.front();
                visited[front] = true;
                q.pop();

                if (front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (parents[front] && !visited[parents[front]]){
                    q.push(parents[front]);
                    visited[parents[front]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode *f = q.front();
            q.pop();
            res.push_back(f->val);
        }
        return res;
    }
};