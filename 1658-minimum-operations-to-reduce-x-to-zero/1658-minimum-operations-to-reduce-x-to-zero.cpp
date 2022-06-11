class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        unordered_map<int, int>mp;
        
    int sum=0, res= INT_MIN, n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mp[sum]=i; //prefix sum with index
            
        }
        
        //cout<<sum;
        int k = sum-x;
        if(k  < 0) return -1;
        sum =0 ; 
        mp[0]=-1;
        //cout<<k;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k) != mp.end())
            {
                res = max(res, i - mp[sum-k] );
            }
        }
        return res==INT_MIN?-1:n-res;
    }
};