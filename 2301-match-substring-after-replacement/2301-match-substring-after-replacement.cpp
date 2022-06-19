class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        



      unordered_map<char, unordered_set<char>> oldToNew;
        int n = s.size(), m = sub.size();
        for(int i = 0; i < mappings.size(); i++) {
            // Converting to a new mapping 'oldToNew' where key is the old character which stores a set of new characters. This is done to find quickly(in O(1)) if there is any character 'new' that can be replaced for any character 'old'
            oldToNew[mappings[i][0]].insert(mappings[i][1]);
        }
        for(int i = 0; i < n - m + 1; i++) {
            for(int j = i; j < i + m; j++) { // Going over every substring of size m in string 's'
                if(s[j] == sub[j - i] || oldToNew[sub[j - i]].find(s[j]) != oldToNew[sub[j - i]].end()) { // Checking if this particular character in sub is or can be same as the character in s
                    if(j == i + m - 1) return true; // if this is the last index, then all previous indices very satisfied and hence we can convert sub to a substring of s
                } else break; // if not possible to convert sub to this particular substring of s, then we break and move to other substrings
            } 
        }
        return false; // If sub cannot be c
}
};