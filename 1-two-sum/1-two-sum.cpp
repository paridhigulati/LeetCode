class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>res;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int tar = target - nums[i];
            if(mp.find(tar) != mp.end())
            {
                res.push_back(i);
                res.push_back(mp[tar]);
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return res;
    }
};