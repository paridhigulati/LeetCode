// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
class Solution{
  public:
  int maxi =0;
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    
    
    int dfs( Node* root, int count, int target)
    {
        if(!root) return 0;
     
      else  if(root->data == target) count++;
      
      else 
      count = 1;
      maxi = max(maxi, count);
      dfs(root->left, count,root->data + 1);
      dfs(root->right, count, root->data + 1);
      
      return maxi;
    }
    int longestConsecutive(Node* root)
    {
          maxi = 0;
        
         dfs(root, 0, 0);
         if(maxi < 2) return -1;
        return maxi;
        
         //Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        cout<<obj.longestConsecutive(root)<<endl;
    }
    return 0;
}
  // } Driver Code Ends