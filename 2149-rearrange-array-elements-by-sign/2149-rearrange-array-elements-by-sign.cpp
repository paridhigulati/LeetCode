class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans, pos, neg; 
        for (auto& x : nums) 
            if (x > 0)
            pos.push_back(x); 
            else neg.push_back(x);
        
        for (int i = 0; i < pos.size(); ++i) {
            ans.push_back(pos[i]); 
            ans.push_back(neg[i]); 
        }
        return ans; 
    }
};