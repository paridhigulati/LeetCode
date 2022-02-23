// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* source =NULL;
int burnTree(unordered_map<Node*,Node*> &parent,unordered_map<Node*,bool>& visited){
queue<Node*> q;
q.push(source);
visited[source] = true;
int res=0;
while(!q.empty()){
int size = q.size();
while(size--){
Node* curr = q.front();
q.pop();
if(parent[curr]!= NULL && visited[parent[curr]]!= true){//check parent
visited[parent[curr]] = true;
q.push(parent[curr]);
}
if(curr->left!=NULL && (visited[curr->left] != true)){ // check left
visited[curr->left] = true;
q.push(curr->left);
}
if(curr->right != NULL && (visited[curr->right]!=true)){ // check right
visited[curr->right] = true;
q.push(curr->right);
}
}
if(q.size() > 0){
res+=1;
}
}
return res;
}
void getParent(unordered_map<Node*,Node*>& parent,Node* root,int target){
if(root!=NULL){
if(root->data == target){
source = root;
}
if(root->left!=NULL){
parent[(root->left)] = root;
}
if(root->right != NULL){
parent[root->right] = root;
}
getParent(parent,root->left,target);
getParent(parent,root->right,target);
}
}
int minTime(Node* root, int target)
{
if(root == NULL){
return -1;
}
unordered_map<Node*,Node*> parent; // node , parent
unordered_map<Node*,bool> visited; // node , bool
parent[root] = NULL;
getParent(parent,root,target);
int res = burnTree(parent,visited);
return res;
}
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends