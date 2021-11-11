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
  /*O(N) TIME
  CASE 1: Both child need camera
Then current node should have camera to satisfy both the children.
If current node has camera, it will return 1 (signifies that this node has a camera)

if(left == -1 || right == -1){
            ++count;
            return 1;
        } 
CASE 2: Any of the child has a camera
Then I am covered by my child's camera. I'll return a 0 which signifies that I don't require a camera and I am already covered by a node below.

else if(left == 1 || right == 1){
            return 0;
        } 
CASE 3: For any other case
Only one case is left which is if left == 0 and right == 0
Which is if both left and right are covered by a node below.
Then there is no point wasting a camera at this node. We instead would like our parent to have a camera to not only cover me but the nodes above. More optimal greedily.

else {
            return -1;
        }
The use of dummy node is that if the root of the given tree has both children covered then it requires a camera.

Example: [0,null,0,null,0,null,0]

In this for the root, left is NULL which we assume to be covered and right which is actually covered.
This is the case when left == 0 and right == 0 at root.
But according to our logic root instead of placing a camera on it's own asks parent to place a camera.
Hence if the dummy knows that my child requires a camera we just ++count to signify that root will place camera on itself.

Example: [0,0,null,null,0,0,null,null,0,0]

In this root does not need to place a camera as one of the child has a camera. So dummy only increments camera if root is in need of camera.

//DUMMY
        if(root->val == INT_MAX && left == -1){
            ++count;
            return 1;
        
};*/
    
    
    
    
    
    
    
    
    
/*  What state should nullptr node represent?

It can not be considered as MONITORED_HAS_CAMERA, otherwise all leave node will not need to be monitored.
It can not be considered as NOT_MONITORED, otherwise we must place cameras in all leave nodes.
It should be considered as MONITORED_NO_CAMERA and it makes no effect t 
    
    
    
    
    
    
    We are going to do a post order traversal.

when a node returns :-

0 -> I am covered, I need nothing
1 -> I have a camera , I got you
-1 -> I am not covered, place a camera to cover me*/


   #define NO_CAMERA      -1
   #define HAS_CAMERA      1
   #define NOT_NEEDED      0
 
    int cam = 0;
    int dfs(TreeNode *root) {
        if (!root) 
     return NOT_NEEDED;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == NO_CAMERA || r == NO_CAMERA) {
            cam++;
            return HAS_CAMERA;
        } else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        } else {
            return NO_CAMERA;
            
        }
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == NO_CAMERA) 
            cam++;
        return cam;
    }
};