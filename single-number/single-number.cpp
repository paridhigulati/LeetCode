class Solution {
public:
    int singleNumber(vector<int>& nums) {
      /*    int a = 0;
    for (int i : nums) {
      a ^= i;
    }
    return a;
  }

     */
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second == 1)
                return it.first;
                
        }
    
        return 0;}
};