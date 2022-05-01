class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
     
        unordered_map<int,int>mp;
        int len = INT_MAX;
       // find the last occur of each element in map
        for(int i=0;i<nums.size();i++)
        {
         if(mp.find(nums[i]) != mp.end())
        {
            len = min(len , (i-mp[nums[i]]+1));
        }
        mp[nums[i]] = i;
    }
      
        if(len==INT_MAX) 
            return -1;
        return len;
        
    }
};