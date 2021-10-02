class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
     // frequency of distinct char should be same 
        // another method, sort the strings and check if same 
        unordered_map<string, vector<string>>v;
        string temp;
        for(int i=0;i<str.size();i++)
        {
            temp = str[i];
            sort(str[i].begin(), str[i].end());
            v[str[i]].push_back(temp); // for tea, we make tea as key in map and push back eat after sorting 
        }
        vector<vector<string>>result;
        for(auto x = v.begin();x!=v.end();x++)
        {
            result.push_back(x->second);
        }
        return result;
    }
};