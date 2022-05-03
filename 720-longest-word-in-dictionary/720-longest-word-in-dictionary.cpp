class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    char val;
    
    TrieNode(){}
    
    TrieNode(char v){ this->val = v; }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode* temp = root;
        
        for(char ch : word){
            if(temp->children.find(ch) == temp->children.end()){
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }
    
    bool isOrdered(string word){
        TrieNode* temp = root;
        
        for(char ch : word){
            if(temp == root || temp->isWord){
                temp = temp->children[ch];
                continue;
            }
            return false;
        }
        
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* search = new Trie();
        string curr ("");
        int size = 0;
        
        for(string str : words){
            search->insert(str);
        }
        
        for(string str : words){
            if(search->isOrdered(str) && size <= str.size()){
                curr = (size == str.size()) ? min(curr, str) : str;
                size = str.size();
            }
        }
        
        return curr;
    }
};