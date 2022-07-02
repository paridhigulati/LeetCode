class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   //     O(nlogk )
        unordered_map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
        }
        int n = nums.size();
       vector<vector<int>>bucket(n , vector<int>());
        
        for(auto i : mp)
        {
            //values in map to be stored as indexes on bucket 
            bucket[i.second -1].push_back(i.first);
        }
        vector<int>ans;
        for(int i = bucket.size()-1; i>=0 and k>0 ; i--)
        {
            for(auto val : bucket[i])
            {
            ans.push_back(val);
                k--;
            }
        }
        return ans;
    }
};
       
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
