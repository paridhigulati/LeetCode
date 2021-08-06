class Solution {
public:
    bool isAnagram(string s, string t) {
  
        if (s==t) return true;
        if (s.size()!=t.size()) return false;
        int umap[26]={};
        for (int i=0; i<s.size(); i++) {
            umap[s[i]-'a']++;
            umap[t[i]-'a']--;
        }
        for (int i=0; i<26; i++) {
            if (umap[i]) return false;
        }
        return true;
    }
};
    

/*

Another way to write the Hashmap Approach
Time Complexity: O (n)
Space Complexity: O(n) (Some may argue it is O (1) because space will be constant, they are correct too.)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s==t) return true;
        if (s.size()!=t.size()) return false;
        unordered_map <char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto it: umap) {
            if (it.second) return false;
        }
        return true;
    }
};*/