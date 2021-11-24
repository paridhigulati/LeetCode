class Solution {
public:
    int majorityElement(vector<int>& nums) {
      map<int,int>mp;
        int n = (nums.size())/2;
        for(int i=0;i< nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x : mp)
        {
            if(x.second > n)
               return x.first;
        }
        return -1;
    }
};