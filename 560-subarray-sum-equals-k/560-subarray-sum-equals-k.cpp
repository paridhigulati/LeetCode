class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     
        unordered_map<int,int>mp{{0,1}};
        int count=0,sum=0;
       
        //mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            
            sum+=nums[i];
           
            

            count+= mp[sum-k];
            mp[sum]++;
         
        }
        return count;
    }
};