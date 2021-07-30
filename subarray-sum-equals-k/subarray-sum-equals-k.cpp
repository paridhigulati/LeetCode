class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sz=nums.size();
        int sum=0;
        int ans=0;
        unordered_map<int,int> mp;
        int r=0;
        while(r<sz)
        {
           sum+=nums[r++];
           if(sum==k)
               ans++;
           if(mp.count(sum-k))
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
    
